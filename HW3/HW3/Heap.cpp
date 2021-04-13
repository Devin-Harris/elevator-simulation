#include <iostream>
#include <vector>
#include "Heap.h"
using namespace std;

template <class T>
Heap<T>::Heap() {
	nodes.clear();
	isMaxHeap = false;
}
template <class T>
Heap<T>::Heap(bool initIsMaxHeap) {
	nodes.clear();
	isMaxHeap = initIsMaxHeap;
};

template <class T>
T Heap <T>::seeRoot() {
	if (nodes.size() > 0) {
		return nodes.at(0);
	}
	else {
		T person;
		return person;
	}
}
template <class T>
T Heap <T>::extractRoot() {
	T root = nodes.at(0);
	nodes.at(0) = nodes.at(nodes.size() - 1);
	nodes.pop_back();

	if (isMaxHeap) {
		maxheapify();
	}
	else {
		minheapify();
	}

	return root;
}
template <class T>
void Heap<T>::insert(T node) {
	nodes.push_back(node);
	int currIndex = nodes.size() - 1;
	bool looping = true;

	while (looping) {
		if (currIndex > 0) {
			if (isMaxHeap) {
				if (nodes.at(currIndex) > nodes.at(getParent(currIndex))) {
					swap(currIndex, getParent(currIndex));
					currIndex = getParent(currIndex);
				}
				else {
					looping = false;
				}
			}
			else {
				if (nodes.at(currIndex) < nodes.at(getParent(currIndex))) {
					swap(currIndex, getParent(currIndex));
					currIndex = getParent(currIndex);
				}
				else {
					looping = false;
				}
			}
		}
		else {
			looping = false;
		}
	}
}
template <class T>
void Heap<T>::setIsMaxHeap(bool m) {
	isMaxHeap = m;
}

template <class T>
void Heap<T>::maxheapify() {
	int currIndex = 0;
	bool looping = true;
	while (looping) {
		bool hasLeft = getLeft(currIndex) < nodes.size();
		bool hasRight = getRight(currIndex) < nodes.size();
		if (hasLeft) {
			if (nodes.at(currIndex) < nodes.at(getLeft(currIndex))) {
				if (hasRight) {
					if (nodes.at(currIndex) < nodes.at(getRight(currIndex))) {
						if (nodes.at(getLeft(currIndex)) > nodes.at(getRight(currIndex))) {
							swap(currIndex, getLeft(currIndex));
							currIndex = getLeft(currIndex);
						}
						else {
							swap(currIndex, getRight(currIndex));
							currIndex = getRight(currIndex);
						}
					}
					else {
						swap(currIndex, getLeft(currIndex));
						currIndex = getLeft(currIndex);
					}
				}
				else {
					swap(currIndex, getLeft(currIndex));
					currIndex = getLeft(currIndex);
				}
			}
			else if (hasRight) {
				if (nodes.at(currIndex) < nodes.at(getRight(currIndex))) {
					swap(currIndex, getRight(currIndex));
					currIndex = getRight(currIndex);
				}
				else {
					looping = false;
				}
			}
			else {
				looping = false;
			}
		}
		else {
			looping = false;
		}
	}
}
template <class T>
void Heap<T>::minheapify() {
	int currIndex = 0;
	bool looping = true;
	while (looping) {
		bool hasLeft = getLeft(currIndex) < nodes.size();
		bool hasRight = getRight(currIndex) < nodes.size();
		if (hasLeft) {
			if (nodes.at(currIndex) > nodes.at(getLeft(currIndex))) {
				if (hasRight) {
					if (nodes.at(currIndex) > nodes.at(getRight(currIndex))) {
						if (nodes.at(getLeft(currIndex)) < nodes.at(getRight(currIndex))) {
							swap(currIndex, getLeft(currIndex));
							currIndex = getLeft(currIndex);
						}
						else {
							swap(currIndex, getRight(currIndex));
							currIndex = getRight(currIndex);
						}
					}
					else {
						swap(currIndex, getLeft(currIndex));
						currIndex = getLeft(currIndex);
					}
				}
				else {
					swap(currIndex, getLeft(currIndex));
					currIndex = getLeft(currIndex);
				}
			}
			else if (hasRight) {
				if (nodes.at(currIndex) > nodes.at(getRight(currIndex))) {
					swap(currIndex, getRight(currIndex));
					currIndex = getRight(currIndex);
				}
				else {
					looping = false;
				}
			}
			else {
				looping = false;
			}
		}
		else {
			looping = false;
		}
	}
}


template <class T>
int Heap<T>::getLeft(int i) {
	return (2 * i) + 1;
}

template <class T>
int Heap<T>::getRight(int i) {
	return (2 * i) + 2;
}

template <class T>
int Heap<T>::getParent(int i) {

	return (i - 1) / 2;
}

template <class T>
int Heap<T>::getSize() {
	return nodes.size();
}

template <class T>
void Heap<T>::swap(int index1, int index2) {
	T temp = nodes.at(index1);
	nodes.at(index1) = nodes.at(index2);
	nodes.at(index2) = temp;
}


