#include <iostream>
#include "Person.h"
#include "Scheduler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Scheduler::Scheduler(int iMinFloors, int iMaxFloors) {
	minFloors = iMinFloors;
	maxFloors = iMaxFloors;
}

Person Scheduler::schedulePerson(int currTime) {
	int initialFloor = rand() % (maxFloors - minFloors) + minFloors;
	int desiredFloor = rand() % (maxFloors - minFloors) + minFloors;
	Person newPerson(initialFloor, desiredFloor, currTime);
	return newPerson;
}