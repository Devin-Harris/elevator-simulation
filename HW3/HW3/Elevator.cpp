#include <iostream>
#include <string>
#include "Elevator.h"

template <class T>
Elevator<T>::Elevator() {
	currentFloor = -1;
	direction = idle;
}

template <class T>
Elevator<T>::Elevator(int floor) {
	currentFloor = floor;
	direction = idle;
}

// Getters
template <class T>
int Elevator<T>::getCurrentFloor() {
	return currentFloor;
}
template <class T>
int Elevator<T>::getNextFloor() {
	if (car.getSize() > 0) {
		T person = car.seeRoot();
		return person.getDesiredFloor();
	}
}
template <class T>
Direction Elevator<T>::getDirection() {
	return direction;
}
template <class T>
Heap<T> Elevator<T>::getCar() {
	return car;
}

//Setters
template <class T>
void Elevator<T>::goToFloor(int floor) {
	currentFloor = floor;
}
template <class T>
void Elevator<T>::setDirection(Direction dir) {
	direction = dir;
	if (dir == up) {
		car.minheapify();
		car.setIsMaxHeap(false);
	}
	else if (dir == down) {
		car.maxheapify();
		car.setIsMaxHeap(true);
	}
}
template <class T>
void Elevator<T>::addToCar(T newPerson) {
	car.insert(newPerson);
}
template <class T>
void Elevator<T>::removePeopleAtDesiredFloor(int time) {
	if (car.getSize() > 0) {
		while (car.seeRoot().getDesiredFloor() == currentFloor) {
			T person = car.extractRoot();
			person.setDesiredFloorArrivalTime(time);
		}
	}
}