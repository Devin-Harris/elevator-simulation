#include <iostream>
#include "Person.h"

using namespace std;

// Constructors
Person::Person() {
	startingFloor = -1;
	desiredFloor = -1;
	elevatorArrivalTime = -1;
}
Person::Person(int iSFloor = -1, int iDFloor = -1, int iATime = -1) {
	startingFloor = iSFloor;
	desiredFloor = iDFloor;
	elevatorArrivalTime = iATime;
}

// Getters
int Person::getStartingFloor() {
	return startingFloor;
}
int Person::getDesiredFloor() {
	return desiredFloor;
}
int Person::getElevatorArrivalTime() {
	return elevatorArrivalTime;
}
int Person::getDesiredFloorArrivalTime() {
	return desiredFloorArrivalTime;
}

// Setters
void Person::setDesiredFloorArrivalTime(int time) {
	desiredFloorArrivalTime = time;
}

// Member Functions
void Person::printPerson() {
	cout << "Starting Floor: " << startingFloor << endl;
	cout << "Desired Floor: " << desiredFloor << endl;
	cout << "Arrived at elevator: " << elevatorArrivalTime << endl;
	cout << "Arrived at desired floor: " << desiredFloorArrivalTime << endl;
	cout << "Total wait time: " << desiredFloorArrivalTime - elevatorArrivalTime << endl;
	cout << endl;
}