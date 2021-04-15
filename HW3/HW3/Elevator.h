#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
#include "Heap.h"
#include "Heap.cpp"
#include "Direction.h"
using namespace std;

template <class T>
class Elevator {
	private:
		int currentFloor;
		Direction direction;
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

};

#endif // !ELEVATOR_H
