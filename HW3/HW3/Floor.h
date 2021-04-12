#pragma once
#ifndef FLOOR_H
#define FLOOR_H

using namespace std;
#include "Button.h"
#include "Person.h"

class Floor {
	private:
		Button upBtn;
		Button downBtn;
		vector<Person> lobby;
		int floorNumber;
	public:
		Floor(int);

		// Getters
		int getFloorNumber();
		bool getUpStatus();
		bool getDownStatus();
		vector<Person> getLobby();

		//Setters
		void setUpStatus(bool);
		void setDownStatus(bool);
		void addPerson(Person);
		void removePerson(Person);


};

#endif // !FLOOR_H
