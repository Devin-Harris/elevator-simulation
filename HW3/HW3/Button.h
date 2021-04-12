#pragma once
#ifndef BUTTON_H
#define BUTTON_H

class Button {
	private:
		bool pressed;
	public:
		Button();

		// Getters
		bool getPressedStatus();

		//Setters
		void setPressedStatus(bool);

};

#endif // !BUTTON_H
