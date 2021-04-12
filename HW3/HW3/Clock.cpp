#include <iostream>
#include "Clock.h"

// Getters
int Clock::getCount() {
	return currCount;
}

bool Clock::getIsCycling() {
	return isCycling;
}


//Setters
void Clock::incCount() {
	currCount++;
}
void Clock::setIsCycling(bool newIsCycling) {
	isCycling = newIsCycling;
}