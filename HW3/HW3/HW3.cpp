#include <iostream>
#include <vector>
#include "Person.h"
#include "Scheduler.h"
#include "Clock.h"
#include "Floor.h"
#include "Heap.h"
#include "Heap.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

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
        // Stop at that floor next

        // If elevator is moving up
        // Pull off lowest floor thats below current floor of elevator in desired floors of people
        // Stop at that floor next

        // If elevator is stopped
        // Let people with desired floors at current floor out
        // Pick up people if people on floor waiting need to go in direction elevator was moving in


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