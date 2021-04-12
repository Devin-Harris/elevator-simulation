#pragma once
#ifndef PERSON_H
#define PERSON_H

class Person {
	private:
		int startingFloor;
		int desiredFloor;
		int arrivalTime;
	public:
		// Constructors
		Person(int iSFloor, int iDFloor, int iATime);

		// Getters
		int getStartingFloor();
		int getDesiredFloor();
		int getArrivalTime();

		// Setters
		
		// Member Functions
		void printPerson();
};


#endif // !PERSON_H
