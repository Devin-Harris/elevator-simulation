#include <iostream>
#include "Button.h"

Button::Button() {
	pressed = false;
}

// Getters
bool Button::getPressedStatus() {
	return pressed;
}

//Setters
void Button::setPressedStatus(bool newStatus) {
	pressed = newStatus;
}