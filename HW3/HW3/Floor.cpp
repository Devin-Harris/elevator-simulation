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
void Floor::removePerson(Person) {

}