/*
 AUTHOR: Bibek Dhungana
 FILENAME: Bibek_Dhungana_hw3.cpp
 DATE: October 5, 2021
 DESCRIPTION: This program takes decimal input from the user and convert it into binary, octal and
              hexdecimal format as required.
 */


//including all the required headers.
#include <iostream>
#include <string>

using namespace std;

//making class to make linkedlist node.
template <class T1>
class LinkedListNode{
public:
    T1 data;
    LinkedListNode* next;
    LinkedListNode(T1 data, LinkedListNode *next = 0){
        this->data = data;
        this->next = 0;
    }
};

//making class for linked list.
template <class T2>
class LinkedList{
private:
    LinkedListNode<T2> *head;
    LinkedListNode<T2> *tail;
public:
    LinkedList(){
        head = tail = 0;
    }
    //function to add element at head.
    void addFirst(int data){
        LinkedListNode<T2> *n = new LinkedListNode<T2>(data);
        //if the list is empty
        if(head == 0){
            head = n;
            tail = n;
        }
        //if the list have more than one element
        else{
            n->next = head;
            head = n;
        }
    }
    //function to remove element from the head.
    int removeFirst(){
        int result = -1;
        // if list is empty
        if(head == 0){
            cout << "The list is empty" << endl;
        }
        //if only one element is present
        else if(head == tail){
            result = head->data;
            delete head;
            head = 0;
            tail = 0;
        }
        //if more than one element is present.
        else{
            result = head->data;
            LinkedListNode<T2> *temp = head;
            head = head->next;
            delete temp;
        }
        return result;
    }
    //method to check if linked list is empty.
    bool isEmpty(){
        return head == 0;
    }
};

//making stack class using linked list
template <class T3>
class Stack{
public:
    bool isEmpty(){
        return l1.isEmpty();
    }
    void push(int data){
        l1.addFirst(data);
    }
    int pop(){
        int element = l1.removeFirst();
        return element;
    }
private:
    LinkedList<T3> l1;
};

//main part of the program
int main() {

    //initializing the required variables.
    Stack<int> resultNumber;
    int inputOption;
    int inputNumber;

    //looping the program.
    while(true){
        //getting the input option.
        cout << "*************************Menu*********************************"<< endl;
        cout << "**        Enter Binary(0),Octal(1) and Hexadecimal(2)       **" << endl;
        cout << "**                  Exit Program(3)                         **" << endl;
        cout << "**************************************************************"<< endl;
        cin >> inputOption;

        //if the option is binary
        if(inputOption == 0){
            //getting input
            cout << "Enter the decimal number to convert into binary:" << endl;
            cin >> inputNumber;

            //checking if the number is positive
            if(inputNumber < 0){
              cout << "The number must be  positive" << endl;
              break;3
            }

            //calculation
            while(inputNumber != 0){
                int remainder = inputNumber % 2;
                resultNumber.push(remainder);
                inputNumber = inputNumber/2;
            }
            //displaying the result
            cout << "Binary Number is  ";
            while(!resultNumber.isEmpty()){
                int items = resultNumber.pop();
                cout << items;
            }
            cout <<endl;
        }
        //if input option is Octal
        else if(inputOption == 1){
            cout << "Enter the decimal number to convert into octal:" << endl;
            cin >> inputNumber;

            //checking if the number is positive
            if(inputNumber < 0){
              cout << "The number must be  positive" << endl;
              break;
            }

            //calculation
            while(inputNumber != 0){
                int remainder = inputNumber % 8;
                resultNumber.push(remainder);
                inputNumber = inputNumber / 8;
            }
            //displaying the result
            cout << "Octal Number is ";
            while(!resultNumber.isEmpty()){
                int items = resultNumber.pop();
                cout << items;
            }
            cout <<endl;
        }
        //if the input option is Heaxdecimal
        else if(inputOption == 2){
            cout << "Enter decimal number to convert into hexadecimal " << endl;
            cin >> inputNumber;

            //checking if the number is positive
            if(inputNumber < 0){
              cout << "The number must be  positive" << endl;
              break;
            }

            //calculation
            while(inputNumber != 0){
                int remainder = inputNumber % 16;
                if (remainder > 9){
                    remainder = 'A' + (remainder - 10);
                    resultNumber.push((char)remainder);
                }
                else{
                    resultNumber.push((char)remainder + '0');
                }
                inputNumber = inputNumber/16;
            }
            //displaying the result
            cout << "Hexadecimal Number is: ";
            while(!resultNumber.isEmpty()){
                char items = resultNumber.pop();
                cout << items;
            }
            cout <<endl;
        }
        //exiting the program
        else if(inputOption == 3){
            cout << "Thank you for using our application" << endl;
            break;

        }
        //if invalid input is provided.
        else{
            cout << "Invalid Input. Please check the instruction." << endl;
        }
    }
    return 0;
}
