#pragma once
#ifndef CLOCK_H
#define CLOCK_H

class Clock {
	private:
		int currCount = 0;
		bool isCycling = true;
	public:
		// Getters
		int getCount();
		bool getIsCycling();

		//Setters
		void incCount();
		void setIsCycling(bool);

};

#endif // !CLOCK_H