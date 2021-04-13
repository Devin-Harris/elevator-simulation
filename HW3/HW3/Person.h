#pragma once
#ifndef PERSON_H
#define PERSON_H

class Person {
	private:
		int startingFloor;
		int desiredFloor;
		int elevatorArrivalTime;
		int desiredFloorArrivalTime = 0;
	public:
		// Constructors
		Person(int iSFloor, int iDFloor, int iATime);

		// Getters
		int getStartingFloor();
		int getDesiredFloor();
		int getElevatorArrivalTime();
		int getDesiredFloorArrivalTime();

		// Setters
		
		// Member Functions
		void printPerson();

		// Overloaded operators
		// used for storing people in a heap later when the elevator is decided the order of the floors to go to
		bool operator>(const Person& comparePerson) {
			return desiredFloor > comparePerson.desiredFloor;
		}
		bool operator<(const Person& comparePerson) {
			return desiredFloor < comparePerson.desiredFloor;
		}
};


#endif // !PERSON_H
