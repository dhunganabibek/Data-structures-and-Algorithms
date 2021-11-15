/*
 *  Stack.cpp
 *  Created on: Nov 14, 2021
 *  Author: Bibek Dhungana
 */
#include "Stack.h"

template <typename T>
T Stack<T>::pop(){
	return s.removeHead();
}

template <typename T>
void Stack<T>::push(T data){
		s.addHead(data);
}

template <typename T>
T Stack<T>::top(){
	return s.head->data;
}

template <typename T>
bool Stack<T>::isEmpty(){
	return s.isEmpty();
}

template class Stack<char>;
template class Stack<int>;


