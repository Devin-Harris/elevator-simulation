#include <iostream>
#include "Person.h"

using namespace std;

// Constructors
Person::Person(int iSFloor = -1, int iDFloor = -1, int iATime = -1) {
	startingFloor = iSFloor;
	desiredFloor = iDFloor;
	arrivalTime = iATime;
}

// Getters
int Person::getStartingFloor() {
	return startingFloor;
}
int Person::getDesiredFloor() {
	return desiredFloor;
}
int Person::getArrivalTime() {
	return arrivalTime;
}

// Setters

// Member Functions
void Person::printPerson() {
	cout << "Starting Floor: " << startingFloor << endl;
	cout << "Desired Floor: " << desiredFloor << endl;
	cout << "Arrival Time : " << arrivalTime << endl;
	cout << endl;
}