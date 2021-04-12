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
};


#endif // !PERSON_H
