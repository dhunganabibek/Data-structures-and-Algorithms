/*
FILE: Assignment 2
AUTHOR: Bibek Dhungana
DATE: September 14, 2021
PURPOSE: Implementation of single and double linked list and make menu driven program
         to apply various operation to both single or double linked list.
*/
//creating the single linked list node

//including all the header file.
#include <iostream>
using namespace std;

/*
Class defination for single linked list node.
This class consists of two instance variables info and next.
*/
class SLLNode{
public:
    //constructor
    SLLNode(){
        next = 0;
    }
    //overloaded constructor and passing default values.
    SLLNode(int i, SLLNode *n = 0){
        info = i;
        next = n;
    }
    //properties/instance variables for the class
    int info;
    SLLNode *next;

};

/*
Class defination for single linked list.
This class consists of two instance variables of head and tail.
This class conssist of all the function that can be applied to SingleLinkedList class object.
*/
class SingleLinkedList{
  //instance variables.
private:
    SLLNode *head, *tail;
public:
    //constructor for single linked list
    SingleLinkedList(){
        head = tail = 0;
    }

    //destructor
    ~SingleLinkedList(){

    }

    /*
    NAME: insertHead
    INPUT: int
    RETURN TYPE: void
    DESCRIPTION: This method is used to insert int Node to the head of single linked list.
    */
    void insertHead(int i){
        SLLNode *temp = new SLLNode(i);
        if(head == 0){
            head = temp;
            tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        cout << "\nThe element is addded successfully." << endl;
    }

    /*
    NAME:deleteHead
    INPUT:void
    RETURN TYPE: int
    DESCRIPTION: This method delete node from the head and return value of deleted node.
    */
    int deleteHead(){
        if(isEmpty()){
            cerr << "Deleting Head Failed: The linked List is empty!!" << endl;
            return -1;
        }else{
          int element = head->info;
          if(head == tail){
              head = tail = 0;
          }
          else{
              SLLNode *temp = head;
              head = head->next;
              delete temp;
            }
            cout << "The element is deleted successfuly." << endl;
            return element;
          }
    }

    /*
    NAME:deleteTail
    INPUT: void
    RETURN TYPE:int
    DESCRIPTION: This method delete node from tail and return the value of deleted node.
    */
    int deleteTail(){
        if(isEmpty()){
            cout << "Deletion from Tail failed!!. The linked list is empty." << endl;
            return -1;
        }
        else{
          int element = tail->info;
          //if there is only one element in the list
          if(head == tail){
              delete head;
              head = tail = 0;
            }
          //if more than one element are present
          else{
              SLLNode *temp;
              for(temp = head; temp->next != tail; temp = temp->next);
              delete tail;
              tail = temp;
              tail->next = 0;
            }
          cout << "The element is deleted successfully." << endl;
          return element;
        }
    }

    /*
    NAME:insertTail
    INPUT: int
    RETURN TYPE: void
    DESCRIPTION: This method insert the node to tail of single linked list.
    */
    void insertTail(int i){
        SLLNode *temp = new SLLNode(i);
        if(head == 0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        cout << "\nThe element is added successfully" << endl;
    }

    /*
    NAME: printSLL
    INPUT: void
    RETURN TYPE: void
    DESCRIPTION: This method print out the number of element pressent in the single linked list in the console.
    */
    void printSLL(){
        cout << "The list is [ ";
        SLLNode* temp = head;
        while(temp != 0){
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    /*
    NAME: searchAndDelete
    INPUT: int
    RETURN TYPE: int
    DESCRIPTION: This function search the element in the list and if found , delete that node from the single
                linked list. If the searched element is not found, it gives the error message to the user.
    */
    int searchAndDelete(int n){
      int result = -1;
      if(isInList(n)){
        result = deleteNode(n);
        cout << "\nThe element is deleted successfully" << endl;
      }
      else{
        cout << "\nThe element is not found in the list";
      }
      return result;
    }

    /*
    NAME:isInList
    INPUT: int
    RETURN TYPE: bool
    DESCRIPTION: This method search the element in the list and return true(1) is found.
                 If the element is not found, it return false(0);
    */
    bool isInList(int e){
        SLLNode *temp;
        temp = head;
        while(temp != 0){
            if(temp->info == e){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    /*
    NAME: deleteNode
    INPUT: int
    RETURN TYPE: void
    DESCRIPTION: This method delete node from the list. If the node is not present in the list,
                 it display node is not found in the list to the user.
    */
    int deleteNode(int e){
        int result = -1;
        //if the list is empty
        if(isEmpty()){
            cout << "Deletion failed..The list is empty!!" << endl;
        }
        //if the list is not empty.
        else{
            // if element not present in the list
            if(!isInList(e)){
                cout << "\nThe element is not present on the list" <<endl;
            }
            //if element is present in the first node
            else if(e == head->info){
                result = head->info;
                deleteHead();
            }
            //delating from tail
            else if(e == tail->info){
                result = tail->info;
                deleteTail();
            }
            //if more than two element are present.
            else{
                SLLNode *pre, *temp;
                for(pre = head, temp = head->next; temp != 0 && (temp->info == e);pre = pre->next,temp = temp->next);
                if(temp != 0){
                    result = temp->info;
                    pre->next = temp->next;
                }
            }
        }
        return result;
    }

    /*
    NAME: isEmpty
    INPUT: void
    RETURN TYPE: bool
    DESCRIPTION: This method check if the list is empty. It return true(1) is list is empty.
                 and false(0) is the list is not empty.
    */
    bool isEmpty(){
        return (head == 0);
    }
};

/*
This class encapsulate the information of info, prev pointer and next pointer as single Node.
It have three instance variables.
info: to store the data.
prev: to store address of previous node.
next: to store address of next node.
*/
class DLLNode{
public:
  //instance variables.
  int info;
  DLLNode *prev,*next;
  //constructor
  DLLNode(int data){
    this->info = data;
    prev = next = 0;
  }
};

/*
This class consists of information about the head and tail pointer of doublyLinkedList.
It also consists of various methods to carry out operation on the given dooubly linked list.
*/
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

  /*
  NAME: insertHead
  INPUT: int
  RETURN TYPE:void
  DESCRIPTION: This method insert the element to head of the doublyLinkedList.
  */
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
    cout << "\nThe element is addded successfully." << endl;
  }

  /*
  NAME:deleteHead
  INPUT:void
  RETURN TYPE:int
  DESCRIPTION: This method delete the node from the head and return the value of deleted node.
               return -1 if the list is empty.
  */
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
      cout << "\n The element is deleted successfully" << endl;
      return element;
    }

  }

  /*
  NAME: insertTail
  INPUT: int
  RETURN TYPE:void
  DESCRIPTION: This method insert the element to tail of the doublyLinkedList.
  */
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
    cout << "\nThe element is added successfully" << endl;
  }

  /*
  NAME: deleteTail
  INPUT: void
  RETURN TYPE: int
  DESCRIPTION: This method delete the element from tail node and return the value of deleted node.
               return -1 if doublyLinkedList is empty.
  */
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
      cout << "\n The element is deleted successfully " << endl;
      return element;
    }
    //if there are more than one element
    else{
      int element = tail->info;
      DLLNode *temp = tail;
      tail = tail->prev;
      tail->next = 0;
      delete temp;
      cout << "\n The element is deleted successfully " << endl;
      return element;
    }
  }

  /*
  NAME:isInList
  INPUT:int
  RETURN TYPE:bool
  DESCRIPTION: This method search the data in the list. return true(1) id the element is present and
              false(0) is the element is not present.
  */
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

  /*
  NAME:deleteNode
  INPUT:int
  RETURN TYPE:int
  DESCRIPTION: This method delete the node from the List and return the value of deleted node.
                 if the element is not present, display the message to the user.
  */
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
      //if data is present on other node.
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

  /*
  NAME: searchAndDelete
  INPUT: int
  RETURN TYPE:void
  DESCRIPTION: This method search the element in doublyLinkedList, then delete the element if
               present in the list. And, display message if the element is not found in list.
  */

  void searchAndDelete(int data){
    if(isInList(data)){
      deleteNode(data);
      cout << "\nThe element is deleted successfuly" << endl;
    }
    else{
      cout << "\nOperation failed!!. The elemnt is not present in the List" << endl;
    }

  }

  /*
  NAME:printDLL
  INPUT:void
  RETURN TYPE: void
  DESCRIPTION: This method print the  elements of doublyLinkedList.
  */
  void printDLL(){
    DLLNode *temp = head;
    cout << "The element in the DoublyLinkedList are:" << endl << "[ ";
    while(temp != 0){
      cout << temp->info << " ";
      temp = temp->next;
    }
    cout << "]" << endl;
  }

  /*
  NAME: printReverseDLL
  INPUT: void
  RETURN TYPE:void
  DESCRIPTION: function to print element of doublyLinkedList in reverse.
  */
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


int main(){
  //required variable to take input from the user
  int menuoption;
  string input;

  //making head for double linked List
  DoublyLinkedList *doublyLinkedList = new DoublyLinkedList();

  //making head pointer for single linked List
  SingleLinkedList *singleLinkedList = new SingleLinkedList();

  //runnning the infinte loop unitil the menuoption is 12
  while (menuoption != 12){
    cout << endl;

    //displaying the menu details to the users.
    cout << "\n************************  MENU  ********************************" << endl;
    cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl;
    cout << "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)" << endl;
    cout << "****************** Enter 12 to exit program ********************\n" << endl;

    //getting the menu input from the user.
    cout << "choose your option:";
    cin >> menuoption;

    //switch case to perform required operation with respect to user input.
    switch(menuoption){
      int data;
      case 0:
        cout << "Enter the data to insert:";
        cin >> data;
        singleLinkedList->insertHead(data);
        break;
      case 1:
        cout << "Enter the data to insert:";
        cin >> data;
        singleLinkedList->insertTail(data);
        break;
      case 2:
        singleLinkedList->deleteHead();
        break;
      case 3:
        singleLinkedList->deleteTail();
        break;
      case 4:
        cout << "Enter the data to search:";
        cin >> data;
        singleLinkedList->searchAndDelete(data);
        break;
      case 5:
        singleLinkedList->printSLL();
        break;
      case 6:
        cout << "Enter the data to insert:";
        cin >> data;
        doublyLinkedList->insertHead(data);
        break;
      case 7:
        cout << "Enter the data to insert:";
        cin >> data;
        doublyLinkedList->insertTail(data);
        break;
      case 8:
        doublyLinkedList->deleteHead();
        break;
      case 9:
        doublyLinkedList->deleteTail();
        break;
      case 10:
        cout << "Enter the data to search:";
        cin >> data;
        doublyLinkedList->searchAndDelete(data);
        break;
      case 11:
        doublyLinkedList->printDLL();
        break;
      case 12:
        break;
      default:
        cout << "Invalid input. Please enter number from 0 to 12." << endl;
        cout << "See menu option for additional details" << endl;

      }
    cout << endl;
  }
  cout << "Thank you so much for using our application." << endl;
  return 0;
}
