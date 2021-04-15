#pragma once
#ifndef BUILDING_H
#define BUILDING_H



using namespace std;

class Building {
private:
	int minFloor;
	int maxFloor;
	vector<Floor> floors;
	Elevator<Person> elevator;
	vector<Person> satisfiedPeople;
public:
	// Constructors
	Building(int iMinFloors, int iMaxFloors);

	// Getters
	int getMinFloor();
	int getMaxFloor();
	int getFloorCount();
	int getNextFloor();
	Floor getFloorAtIndex(int index);
	Direction getElevatorDirection();
	int getElevatorFloor();
	int getElevatorSize();
	int checkUpFromIndexToIndex(int fromIndex, int toIndex);
	int checkDownFromIndexToIndex(int fromIndex, int toIndex);
	double getAverageWaitTime();

	// Setters
	void goToFloor(int floorNum);
	void removePeopleAtDesiredFloor(int time);
	void setFloorUp(int floorNum, bool status);
	void setFloorDown(int floorNum, bool status);
	void addPersonToFloorAtIndex(int index, Person temp);
	void loadElevatorCar();
	void openElevator();
	void closeElevator();

	// Member Functions
	void printBuildingInfo(int time);
	void printFloorInfo();
	void printElevatorInfo();
	void printTransportedPeopleInfo();
};


#endif // !BUILDING_H