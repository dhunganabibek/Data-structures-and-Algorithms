/*
 *	LinkedList.h
 *	Created on: Nov 14, 2021
 *  Author: Bibek Dhungana
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	//instance varibales.
	T data;
	Node* next;
	Node* prev;
	//constructor
	Node(T data,Node* next = 0,Node* prev = 0){
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

template <class X>
class LinkedList{
public:
	//constructor
	LinkedList(){
		head = tail = 0;
	}

	//function to add element to the head
	void addHead(X data){
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

	//function to add element to the head
	void addTail(X data){
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

	//function to remove the element from the head
	X removeHead(){
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

	//function to remove the elemnt from the tail
	X removeTail(){
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
	//functiom to print elmeents of linked list
	void printLinkedList(){
		Node<X>* t = head;
		while(t != 0){
			cout << t->data;
			t = t->next;
		}
	}
	// function to print element of linked list in reverse
	void printLinkedListReverse(){
		Node<X>* t = tail;
		while(t != 0){
			cout << t->data;
			t = t->prev;
		}
	}

	//function to check if linked list is empty
	bool isEmpty(){
		return head == 0;
	}

	Node<X>* head;
	Node<X>* tail;

};



#endif /* LINKEDLIST_H_ */
