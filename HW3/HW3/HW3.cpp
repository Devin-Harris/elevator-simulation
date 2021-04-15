#include <iostream>
#include <vector>
#include "Person.h"
#include "Scheduler.h"
#include "Clock.h"
#include "Floor.h"
#include "Elevator.h"
#include "Elevator.cpp"
#include "Direction.h"
#include "Building.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>


using namespace std;

int main()
{
    srand(time(NULL));

    // For prompting to continue simulation
    int promptRate = 20;
    int promptCount = promptRate;

    int minFloor = 3;
    int maxFloor = 8;
    Building building(minFloor, maxFloor);

    Scheduler scheduler(minFloor, maxFloor);
    Clock clock;
    // While clock is cycling run simulation
    while (clock.getIsCycling()) {

        cout << "Time: " << clock.getCount() << endl;

        // 1 in 3 chance every new time increment a new person needs to use the elevator
        if (rand() % 3 == 0) {
            Person temp = scheduler.schedulePerson(clock.getCount());

            // Need to store these people into a queue based on there current floors
            // Check if person is already at desired floor
            if (temp.getDesiredFloor() != temp.getStartingFloor()) {
                //Find the floor the person is on and add them to the lobby
                for (int i = 0; i < building.getFloorCount(); i++) {
                    if (i + minFloor == temp.getStartingFloor()) {
                        cout << endl << "--------- New Person Alert ---------" << endl;
                        cout << "Adding person to floor " << i + minFloor << endl;
                        building.addPersonToFloorAtIndex(i, temp);
                        if (temp.getDesiredFloor() > temp.getStartingFloor()) {
                            cout << "Person wants to go up to " << temp.getDesiredFloor() << endl;
                            building.setFloorUp(i, true);
                        }
                        else if (temp.getDesiredFloor() < temp.getStartingFloor()) {
                            cout << "Person wants to go down to " << temp.getDesiredFloor() << endl;
                            building.setFloorDown(i, true);
                        }
                    }
                }
            }
        }

        int prevFloor = building.getElevatorFloor();
        building.goToFloor(building.getNextFloor());
        int newFloor = building.getElevatorFloor();
        if (prevFloor != newFloor) {
            cout << endl << "Elevator moving to " << prevFloor << " from " << newFloor << endl;
        }
        // Add 1 extra time unit for every floor the elevator needs to move through to get to the next floor
        for (int i = 0; i < abs(newFloor - prevFloor); i++) {
            clock.incCount();
            cout << "Time: " << clock.getCount() << endl;
        }

        // If elevator is stopped
        // Let people with desired floors at current floor out
        // Pick up people if people on floor waiting need to go in direction elevator is moving in
        int cartSizeBefore = 0;
        int cartSizeAfter = 0;

        cartSizeBefore = building.getElevatorSize();
        building.removePeopleAtDesiredFloor(clock.getCount());
        cartSizeAfter = building.getElevatorSize();
        if (cartSizeBefore - cartSizeAfter > 0) {
            cout << endl << "Dropped off " << cartSizeBefore - cartSizeAfter << " people" << endl;
        }

        cartSizeBefore = building.getElevatorSize();
        building.loadElevatorCar();
        cartSizeAfter = building.getElevatorSize();
        if (cartSizeAfter - cartSizeBefore > 0) {
            cout << endl << "Picked up " << cartSizeAfter - cartSizeBefore << " people" << endl;
        }

        clock.incCount();
        // Ask around every 20 time units if user want to continue simulation
        if (clock.getCount() >= promptCount && clock.getCount() != 0) {
            char ans;
            cout << endl << "Continue the simulation? (y, n)" << endl;
            cin >> ans;
            clock.setIsCycling((!(ans == 'n' || ans == 'N')));
            cout << endl;
            promptCount += promptRate;
        }
    }

    building.printTransportedPeopleInfo();
}