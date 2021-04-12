#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {
	private:
		int minFloors;
		int maxFloors;
	public:
		// Constructors
		Scheduler(int iMinFloors, int iMaxFloors);

		// Getters

		// Setters

		// Member Functions
		Person schedulePerson(int currTime);
};


#endif // !PERSON_H