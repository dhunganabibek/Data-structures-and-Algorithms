/*
 *	Queue.h
 *  Created on: Nov 14, 2021
 *  Author: Bibek Dhungana
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "LinkedList.h"

template <class T>
class Queue{
public:
	void enqueue(T data);
	T dequeue();
	T front();
	bool isEmpty();

private:
	LinkedList<T> q;
};

#endif
