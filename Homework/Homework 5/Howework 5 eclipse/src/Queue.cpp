/*
 *  Queue.cpp
 *  Created on: Nov 14, 2021
 *  Author: Bibek Dhungana
 */
#include "Queue.h"

template <typename T>
void Queue<T>::enqueue(T data){
	q.addTail(data);
}

template <typename T>
T Queue<T>::dequeue(){
	return q.removeHead();
}

template <typename T>
T Queue<T>::front(){
	return q.head->data;
}

template <typename T>
bool Queue<T>::isEmpty(){
	return q->isEmpty();
}

template class Queue<int>;
template class Stack<char>;



