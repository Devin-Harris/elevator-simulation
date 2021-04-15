#pragma once
#ifndef DOOR_H
#define DOOR_H

class Door {
private:
	bool open;
public:
	Door();

	// Getters
	bool getOpenedStatus();

	//Setters
	void setOpenedStatus(bool);

};

#endif // !DOOR_H
