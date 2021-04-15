#include <iostream>
#include "Door.h"

Door::Door() {
	open = false;
}

// Getters
bool Door::getOpenedStatus() {
	return open;
}

//Setters
void Door::setOpenedStatus(bool newStatus) {
	open = newStatus;
}