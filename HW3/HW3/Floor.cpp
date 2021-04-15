#include <iostream>
#include <vector>
#include "Button.h"
#include "Person.h"
#include "Floor.h"

// Constructor
Floor::Floor(int floorNum) {
	upBtn.setPressedStatus(false);
	downBtn.setPressedStatus(false);
	lobby.clear();
	floorNumber = floorNum;
}

// Getters
int Floor::getFloorNumber() {
	return floorNumber;
}
bool Floor::getUpStatus() {
	return upBtn.getPressedStatus();
}
bool Floor::getDownStatus() {
	return downBtn.getPressedStatus();
}
vector<Person> Floor::getLobby()  {
	return lobby;
}

//Setters
void Floor::setUpStatus(bool newStatus) {
	upBtn.setPressedStatus(newStatus);
}
void Floor::setDownStatus(bool newStatus) {
	downBtn.setPressedStatus(newStatus);
}
void Floor::addPerson(Person newPerson) {
	lobby.push_back(newPerson);
}
void Floor::removePerson(Person delPerson) {
	// Just removing people based on their arrival time
	// Is unique in this simulation, but in the future possibly adding an id to each person
	// and removing based on that id would be better

	for (int i = 0; i < lobby.size(); i++) {
		if (lobby.at(i).getElevatorArrivalTime() == delPerson.getElevatorArrivalTime()) {
			lobby.erase(lobby.begin() + i);
		}
	}
}