#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
#include "Heap.h"
#include "Heap.cpp"
#include "Direction.h"
#include "Door.h"

using namespace std;

template <class T>
class Elevator {
	private:
		int currentFloor;
		Direction direction;
		Door door;
		Heap<T> car;
	public:

		Elevator();
		Elevator(int);

		// Getters
		int getCurrentFloor();
		Direction getDirection();
		int getNextFloor();
		Heap<T> getCar();

		//Setters
		void goToFloor(int);
		void setDirection(Direction);
		void addToCar(T);
		void removePeopleAtDesiredFloor(int);
		void openDoor();
		void closeDoor();

};

#endif // !ELEVATOR_H
