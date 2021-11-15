
#include <iostream>

using namespace std;

//creating the single linked list node
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

//making class for single linked list
class SingleLinkedList{
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
    //insertHead function
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
    }
    //deleteHead function
    int deleteHead(){
        if(isEmpty()){
            cerr << "Deleting Head Failed: The linked List is empty!!" << endl;
            return -1;
        }

        else if(head == tail){
            int element = head->info;
            head = tail = 0;
            return element;
        }
        else{
            int element = head->info;
            SLLNode *temp = head;
            head = head->next;
            delete temp;
            return element;
        }

    }

    //deleteTail function
    int deleteTail(){
        if(isEmpty()){
            cout << "Deletion from Tail failed!!. The linked list is empty." << endl;
            return -1;
        }

        //if there is only one element in the list
        if(head == tail){
            int element = tail->info;
            delete head;
            head = tail = 0;
            return element;
        }
        //if more than one element are present
        else{
            int element = tail->info;
            SLLNode *temp;
            for(temp = head; temp->next != tail; temp = temp->next);
            delete tail;
            tail = temp;
            tail->next = 0;
            return element;
        }


    }

    //insertTail function
    void insertTail(int i){
        SLLNode *temp = new SLLNode(i);
        if(head == tail){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    //print single linked list
    void printSLL(){
        cout << "The list is [ ";
        SLLNode* temp = head;
        while(temp != 0){
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }
    //function searchAndDelete()
    void searchAndDelete(int n){
      if(isInList(n)){
        deleteNode(n);
      }
      else{
        cout << "The elemnt is not found in the list";
      }

    }

    //function to search element in the list
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

    void deleteNode(int e){
        //if the list is empty
        if(isEmpty()){
            cout << "Deletion failed..The list is empty!!" << endl;
        }
        else{
            // if element not present in the list
            if(!isInList(e)){
                cout << "The element is not present on the list" <<endl;
            }
            //if element is present in the first node
            else if(e == head->info){
                deleteHead();
            }
            else if(e == tail->info){
                deleteTail();
            }
            else{
                SLLNode *pre, *temp;
                for(pre = head, temp = head->next; temp != 0 && (temp->info == e);pre = pre->next,temp = temp->next);
                if(temp != 0){
                    pre->next = temp->next;

                }

            }
        }
    }
    //checking is list is empty
    bool isEmpty(){
        return (head == 0);
    }




};



int main(void){
    //making object for SLLNode class
    SingleLinkedList *l1 = new SingleLinkedList();
    l1->insertHead(1);
    l1->insertHead(2);
    l1->insertHead(3);
    l1->insertHead(4);
    l1->insertHead(5);

    l1->searchAndDelete(3);




    l1->printSLL();



    return 0;
}
