#include <iostream>
#include "Person.h"
#include "Scheduler.h"
#include "Clock.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main()
{
    srand(time(NULL));

    Scheduler scheduler(3, 8);

    Clock clock;

    while (clock.getIsCycling()) {

        int clockCycles = 0;
        cout << "How many clock cycles do you want to perform? (0 to quit the simulation)" << endl;
        cin >> clockCycles;

        if (clockCycles == 0) {
            clock.setIsCycling(false);
            break;
        }

        for (int i = 0; i < clockCycles; i++) {
            Person temp = scheduler.schedulePerson(clock.getCount());
            temp.printPerson();

            // Need to store these people into a queue based on there current floors and the floors they need to get to
            // That queue tells the elevator which direction to go (up or down)

            clock.incCount();
        }

    }
}