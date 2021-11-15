#include <iostream>

using namespace std;

//creating double linked list node.
class DLLNode{
public:
  int info;
  DLLNode *prev,*next;
  DLLNode(int data){
    this->info = data;
    prev = next = 0;
  }
};

class DoublyLinkedList{
public:
  //instance variables
  DLLNode *head;
  DLLNode *tail;
  //constructor for DoublyLinkedList
  DoublyLinkedList(){
    head = 0;
    tail = 0;
  }
  //function to insert element to the heaf
  void insertHead(int data){
    DLLNode *temp = new DLLNode(data);
    if(head == 0){
      head = temp;
      tail = temp;
    }
    else{
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
  }

  //function to delete element from linked List
  int deleteHead(){
    //if the list is empty
    if (head == 0){
      cout << "Operation Failed!!. The list is empty" << endl;
      return -1;
    }
    //if the list has only one element
    else if( head == tail){
      int element =  head->info;
      delete head;
      head = tail = 0;
      return element;
    }
    //if the list more than one element.
    else{
      int element = head->info;
      DLLNode *temp = head;
      head = head ->next;
      head->prev = 0;
      delete temp;
      return element;
    }
    return -1;
  }
  //function to insert element in the Tail
  void insertTail(int data){
    DLLNode *temp = new DLLNode(data);
    //if the list is empty
    if (head == 0){
      head = tail = temp;
    }else{
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }

  //function to delete tail from linked List
  int deleteTail(){
    //if the list is empty
    if (head == 0){
      cout << "Operation failed!!. The list is empty.";
      return -1;
    }
    //if the list have only one element
    else if (head == tail){
      int element = head->info;
      delete head;
      head = tail = 0;
      return element;
    }
    //if there are more than one element
    else{
      int element = tail->info;
      DLLNode *temp = tail;
      tail = tail->prev;
      tail->next = 0;
      delete temp;
      return element;

    }
  }
  //function to check if the element is present in the List
  //return true(1) is element is present and false(0) is element is absent.
  bool isInList(int data){
    DLLNode *temp = head;
    while(temp != 0){
      if(temp->info == data){
        return true;
      }
      temp=  temp->next;
    }
    return false;
  }

  //functiont to delete the node from the List and return the value of deleted node.
  int deleteNode(int data){
    //if element is presnt in the list
    if(isInList(data)){
      //if data is present on the first node
      if(data == head->info){
        deleteHead();
      }
      //if data is present on tail node
      else if(data == tail->info){
        deleteTail();
      }
      else{
        DLLNode *temp = head;
        while(temp->info != data){
          temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
      }
      return data;
    }
    //if the element is not present in the list.
    else{
      cout << "Operation failed!!. The element is not present in the list" << endl;
      return -1;
    }

  }
  //search and  Delete Implementation of doublyLinkedList
  void searchAndDelete(int data){
    if(isInList(data)){
      deleteNode(data);
    }
    else{
      cout << "Operation failed!!. The elemnt is not present in the List" << endl;
    }

  }

  //function to print the element of double linked list
  void printDLL(){
    DLLNode *temp = head;
    cout << "The element in the DoublyLinkedList are:" << endl << "[ ";
    while(temp != 0){
      cout << temp->info << " ";
      temp = temp->next;
    }
    cout << "]" << endl;
  }
  //function to print element of doublyLinkedList in reverse
  void printReverseDLL(){
    DLLNode *temp = tail;
    cout << "The element in the DoublyLinkedList in reverse are:" << endl << "[ ";
    while(temp != 0){
      cout << temp->info << " ";
      temp = temp->prev;
    }
    cout << "]" << endl;
  }


};

int main(void){
  DoublyLinkedList *doublyLinkedList = new DoublyLinkedList();
  



  return 0;
}
