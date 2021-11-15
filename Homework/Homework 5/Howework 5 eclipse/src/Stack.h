/*
 * 	Stack.h
 *  Created on: Nov 14, 2021
 *  Author: Bibek Dhungana
 */

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

template <class T>
class Stack{
public:
	void push(T data);
	T pop();
	T top();
	bool isEmpty();
private:
	LinkedList<T> s;
};
#endif

