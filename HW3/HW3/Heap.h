#pragma once
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Heap {
	private:
		vector<T> nodes;
		bool isMaxHeap;
	public:

		Heap(bool);

		T extractRoot();
		void insert(T);

		void swap(int index1, int index2);
		int getLeft(int i);
		int getRight(int i);
		int getParent(int i);

		void maxheapify();
		void minheapify();


};


#endif // !HEAP_H
