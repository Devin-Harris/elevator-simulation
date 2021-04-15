#include <iostream>
#include <vector>
#include "Floor.h"
#include "Person.h"
#include "Elevator.h"
#include "Elevator.cpp"
#include "Building.h"
#include "Direction.h"

Building::Building(int iMinFloors, int iMaxFloors) {
	minFloor = iMinFloors;
	maxFloor = iMaxFloors;
	for (int i = minFloor; i <= maxFloor; i++) {
		Floor newFloor(i);
		floors.push_back(newFloor);
	}
	elevator.goToFloor(minFloor);
	elevator.setDirection(idle);
}

// Getters
int Building::getMinFloor() {
	return minFloor;
}
int Building::getMaxFloor() {
	return maxFloor;
}

int Building::getFloorCount() {
	return floors.size();
}
Floor Building::getFloorAtIndex(int index) {
	return floors.at(index);
}
Direction Building::getElevatorDirection() {
	return elevator.getDirection();
}
int Building::getElevatorFloor() {
	return elevator.getCurrentFloor();
}
int Building::getElevatorSize() {
	return elevator.getCar().getSize();
}

int Building::checkUpFromIndexToIndex(int fromIndex, int toIndex) {
	int nextFloor = 0;
	if (fromIndex > toIndex) return 0;
	for (int i = fromIndex + 1; i < toIndex; i++) {
		if (floors.at(i).getUpStatus()) {
			nextFloor = i;
			break;
		}
	}
	return nextFloor;
}
int Building::checkDownFromIndexToIndex(int fromIndex, int toIndex) {
	int nextFloor = 0;
	if (fromIndex < toIndex) return 0;
	for (int i = fromIndex - 1; i > toIndex; i--) {
		if (floors.at(i).getDownStatus()) {
			nextFloor = i;
			break;
		}
	}
	return nextFloor;
}
int Building::getNextFloor() {
	// Check if any floors in between next floor for elevator and current floor have people waiting who want to go down/up
	// If so, stop at that floor and let them on
	// otherwise go to next floor of elevator heap
	Floor elevatorNextFloor = elevator.getNextFloor();
	int currFloor = getElevatorFloor();
	int nextFloor = 0;

	if (elevatorNextFloor.getFloorNumber() == getMinFloor() && getElevatorDirection() == down) {
		elevator.setDirection(idle);
	}
	if (elevatorNextFloor.getFloorNumber() == getMaxFloor() && getElevatorDirection() == up) {
		elevator.setDirection(idle);
	}
	if (elevator.getCar().getSize() == 0) {
		elevator.setDirection(idle);
	}

	if (getElevatorDirection() == up) {
		if (elevatorNextFloor.getFloorNumber() - currFloor > 1) {
			int temp = checkUpFromIndexToIndex(currFloor - getMinFloor(), elevatorNextFloor.getFloorNumber() - getMinFloor());
			if (temp == 0) {
				nextFloor = elevatorNextFloor.getFloorNumber() - getMinFloor();
			}
			else {
				nextFloor = temp;
			}
		}
		else {
			nextFloor = elevatorNextFloor.getFloorNumber() - getMinFloor();
		}
	}
	else if (getElevatorDirection() == down) {
		if (currFloor - elevatorNextFloor.getFloorNumber() > 1) {
			int temp = checkDownFromIndexToIndex(elevatorNextFloor.getFloorNumber() - getMinFloor(), currFloor - getMinFloor());
			if (temp == 0) {
				nextFloor = elevatorNextFloor.getFloorNumber() - getMinFloor();
			}
			else {
				nextFloor = temp;
			}
		}
		else {
			nextFloor = elevatorNextFloor.getFloorNumber() - getMinFloor();
		}
	}
	else if (getElevatorDirection() == idle) {
		for (int i = 0; i < getFloorCount(); i++) {
			if (floors.at(i).getUpStatus() && (i != currFloor - getMinFloor() || currFloor == getMinFloor() )) {
				nextFloor = i;
				elevator.setDirection(up);
				break;
			}
		}
		if (nextFloor == 0) {
			for (int i = getFloorCount() - 1; i >= 0; i--) {
				if (floors.at(i).getDownStatus() && (i != currFloor - getMinFloor() || currFloor == getMinFloor())) {
					nextFloor = i;
					elevator.setDirection(down);
					break;
				}
			}
			if (nextFloor == 0) {
				return currFloor;
			}
		}
	}


	return nextFloor + getMinFloor();
}
double Building::getAverageWaitTime() {
	int count = 0;
	int totalTime = 0;
	for (int i = 0; i < satisfiedPeople.size(); i++) {
		totalTime = satisfiedPeople.at(i).getDesiredFloorArrivalTime() - satisfiedPeople.at(i).getElevatorArrivalTime();
		count += totalTime;
	}
	return count / satisfiedPeople.size();
}

// Setters
void Building::goToFloor(int floorNum) {
	elevator.goToFloor(floorNum);
}
void Building::removePeopleAtDesiredFloor(int time) {
	int currentFloor = getElevatorFloor();
	Heap<Person> car = elevator.getCar();
	if (car.getSize() > 0) {
		while (car.seeRoot().getDesiredFloor() == currentFloor) {
			Person person = car.extractRoot();
			person.setDesiredFloorArrivalTime(time);
			// Add to satisifed people (for calculating average times later)
			satisfiedPeople.push_back(person);
		}
	}
	elevator.removePeopleAtDesiredFloor(time);
}
void Building::setFloorUp(int floorNum, bool status) {
	floors.at(floorNum).setUpStatus(status);
}
void Building::setFloorDown(int floorNum, bool status) {
	floors.at(floorNum).setDownStatus(status);
}
void Building::addPersonToFloorAtIndex(int index, Person temp) {
	floors.at(index).addPerson(temp);
}
void Building::loadElevatorCar() {
	int currFloor = getElevatorFloor() - getMinFloor();
	if (currFloor < 0) {
		return;
	}
	vector<Person> currLobby = floors.at(currFloor).getLobby();
	vector<Person> peopleToAddToCar;
	for (int i = 0; i < currLobby.size(); i++) {
		Direction personDir = idle;
		if (currLobby.at(i).getDesiredFloor() - currLobby.at(i).getStartingFloor() > 0) {
			personDir = up;
		}
		else {
			personDir = down;
		}

		if (personDir == getElevatorDirection()) {
			// Add to elevator car
			peopleToAddToCar.push_back(currLobby.at(i));
			// Remove from lobby
			floors.at(currFloor).removePerson(currLobby.at(i));
			// Reset floors status
			if (getElevatorDirection() == up) {
				floors.at(currFloor).setUpStatus(false);
			}
			else if (getElevatorDirection() == down) {
				floors.at(currFloor).setDownStatus(false);
			}
		}
	}

	for (int j = 0; j < peopleToAddToCar.size(); j++) {
		elevator.addToCar(peopleToAddToCar.at(j));
	}
}

void Building::printBuildingInfo(int time) {
	cout << "Current iteration: " << time << endl;
	printElevatorInfo();
	printFloorInfo();
	cout << endl;
}
void Building::printFloorInfo() {
	cout << "Floors Info: --------------" << endl;
	for (int i = 0; i < floors.size(); i++) {
		cout << "Floor " << i + getMinFloor() << endl;
		cout << "Lobby size: " << floors.at(i).getLobby().size() << endl;
		cout << "Up status: " << floors.at(i).getUpStatus() << endl;
		cout << "Down status: " << floors.at(i).getDownStatus() << endl;
		cout << endl;
	}
}
void Building::printElevatorInfo() {
	cout << "Elevator Info: --------------" << endl;
	cout << "Current Floor: " << elevator.getCurrentFloor() << endl;
	cout << "Next floor destination: " << elevator.getNextFloor() << endl;
	cout << "Person Count: " << elevator.getCar().getSize() << endl;
	cout << "Direction: " << elevator.getDirection() << endl;
	cout << endl;
}
void Building::printTransportedPeopleInfo() {
	cout << "-------------- Transported People Info --------------" << endl;
	cout << "Number of people helped: " << satisfiedPeople.size() << endl;
	cout << "Average wait time: " << getAverageWaitTime() << endl;
	cout << endl;
}
