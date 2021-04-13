#include <iostream>
#include <vector>
#include "Person.h"
#include "Scheduler.h"
#include "Clock.h"
#include "Floor.h"
#include "Elevator.h"
#include "Elevator.cpp"
#include "Direction.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
void elevatorTest() {
    int minFloor = 3;
    int maxFloor = 8;
    Scheduler scheduler(minFloor, maxFloor);
    Elevator<Person> elevator(1);

    for (int i = 0; i < 4; i++) {
        Person temp = scheduler.schedulePerson(i);
        elevator.addToCar(temp);
    }
}

int main()
{
    srand(time(NULL));

    // These lines will be re incorporated into the building class
    int minFloor = 3;
    int maxFloor = 8;

    // These lines will be re incorporated into the building class
    vector<Floor> floors;
    for (int i = minFloor; i <= maxFloor; i++) {
        Floor newFloor(i);
        floors.push_back(newFloor);
    }

    // These lines will be re incorporated into the building class
    Elevator<Person> elevator(minFloor);
    elevator.setDirection(idle);

    Scheduler scheduler(minFloor, maxFloor);
    Clock clock;
    // While clock is cycling run simulation
    while (clock.getIsCycling()) {

        // 1 in 3 chance every new time increment a new person needs to use the elevator
        if (rand() % 3 == 0) {
            Person temp = scheduler.schedulePerson(clock.getCount());

            // Need to store these people into a queue based on there current floors
            // Check if person is already at desired floor
            if (temp.getDesiredFloor() != temp.getStartingFloor()) {
                //Find the floor the person is on and add them to the lobby
                for (int i = 0; i < floors.size(); i++) {
                    if (floors.at(i).getFloorNumber() == temp.getStartingFloor()) {
                        floors.at(i).addPerson(temp);
                    }
                }
            }
        }

        // If elevator is moving down
        // Pull off highest floor thats below current floor of elevator in desired floors of people
        if (elevator.getDirection() == down) {
            // Check if any floors in between next floor for elevator and current floor have people waiting who want to go down
            // If so, stop at that floor and let them on

            // otherwise go to next floor of elevator heap
            elevator.goToFloor(elevator.getNextFloor());
        }

        // If elevator is moving up
        // Pull off lowest floor thats below current floor of elevator in desired floors of people
        if (elevator.getDirection() == up) {
            // Check if any floors in between next floor for elevator and current floor have people waiting who want to go up
            // If so, stop at that floor and let them on

            // otherwise go to next floor of elevator heap
            elevator.goToFloor(elevator.getNextFloor());
        }

        // If elevator is stopped
        // Let people with desired floors at current floor out
        // Pick up people if people on floor waiting need to go in direction elevator is moving in
        elevator.removePeopleAtDesiredFloor(clock.getCount());

        clock.incCount();
        // Ask every 20 time units if user want to continue simulation
        if (clock.getCount() % 20 == 0 && clock.getCount() != 0) {
            char ans;
            cout << "Continue the simulation? (y, n)" << endl;
            cin >> ans;
            clock.setIsCycling((!(ans == 'n' || ans == 'N')));
        }
    }
}