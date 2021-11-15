/*
 * 	LinkedList.cpp
 *  Created on: Nov 14, 2021
 *  Author: Bibek Dhungana
 */
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename X>
void LinkedList<X>::addHead(X data){
	Node<X>* t = new Node<X>(data);
	if(head == 0){
		head = tail = t;
	}
	else{
		t->next = head;
		head->prev = t;
		head = t;
	}

}

template <typename X>
void LinkedList<X>::addTail(X data){
	Node<X>* t = new Node<X>(data);
	if(head == 0){
		head = tail = t;
	}
	else{
		tail->next = t;
		t->prev = tail;
		tail = t;
	}

}

template <typename X>
X LinkedList<X>::removeHead(){
	X dataRemoved = head->data;

	if(head == tail){
		delete head;
		head = tail = 0;
	}
	else{
		Node<X>* t = head;
		head = head->next;
		head->prev = 0;
		delete t;
	}
	return dataRemoved;
}

template <typename X>
X LinkedList<X>::removeTail(){
	X dataRemoved = tail->data;
	if(head == tail){
		delete tail;
		head = tail = 0;
	}else{
		tail = tail->prev;
		delete(tail->next);
		tail->next = 0;
	}
	return dataRemoved;
}


template <typename X>
void LinkedList<X>::printLinkedList(){
	Node<X>* t = head;
	while(t != 0){
		cout << t->data;
		t = t->next;
	}
}


template <typename X>
void LinkedList<X>::printLinkedListReverse(){
	Node<X>* t = tail;
	while(t != 0){
		cout << t->data;
		t = t->prev;
	}
}

template <typename X>
bool LinkedList<X>::isEmpty(){
	return head == 0;
}

template class LinkedList<int>;
template class LinkedList<char>;



