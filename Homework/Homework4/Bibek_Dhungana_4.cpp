/*
AUTHOR: Bibek Dhungana
FILENAME:Bibek_Dhungana_4.cpp
DATE: September 24,2021
DESCRIPTION: This code is implementation of binary tree, conduct various standard operatio such as insert, delete ,search, traversal(preorder, postorder,inorder and breadth first).
*/

//including all the required libraries.
#include <iostream>
#include <queue>
#include <sstream>  //use for string tokenization
using namespace std;

//Node for the binary tree
class BinaryTreeNode{
public:
    //instance variables.
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    //constructor
    BinaryTreeNode(int data,BinaryTreeNode* left = 0, BinaryTreeNode* right = 0){
        this->data = data;
        this->left = left;
        this->right = right;

    }
};

//class for binary tree
class BinaryTree{
public:
    //constructor
    BinaryTree(){
        root = 0;
    }
    //overloaded constructor
    BinaryTree(int data){
        root = new BinaryTreeNode(data);
    }

    //insert function.
    void insert(int data){
       root = insert(root,data);
    }

    //inorder traversal
    void inorder(){
       inorder(root);
    }

    //preorder traversal
    void preorder(){
        preorder(root);
    }

    //postorder traversal
    void postorder(){
        postorder(root);
    }

    //Breath first Traversal
    void breadthFirst(){
        breadthFirst(root);
    }

    //search function
    BinaryTreeNode* search(int data){
        return search(root,data);
    }

    //delete function
    BinaryTreeNode* remove(int data){
        return remove(root,data);
    }

    //height function
    int height(){
       return height(root);
    }
    //method to find maximum element of the tree
    BinaryTreeNode* max(){
        return max(root);
    }

    //method to find minimum element of the tree
    BinaryTreeNode* min(){
        return min(root);
    }

private:
    //instamce variables
    BinaryTreeNode *root;

    //inorderTraversal
    void inorder(BinaryTreeNode* r){
        if(r == 0){
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    //preorder traversal
    void preorder(BinaryTreeNode* r){
        if(r == 0){
            return;
        }
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    //postorder traversal
    void postorder(BinaryTreeNode* r){
        if(r == 0){
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }

    //breadth first traversal
    void breadthFirst(BinaryTreeNode* r){
        //if the root is empty
        if(r == 0){
            return;
        }
        //is the root is not empty
        else{
            queue<BinaryTreeNode*> q1;
            q1.push(r);
            while(q1.empty() == 0){
                BinaryTreeNode* n = q1.front();
                cout << n->data << " ";

                if(n->left != 0){
                    q1.push(n->left);
                }
                if(n->right != 0){
                    q1.push(n->right);
                }
                q1.pop();
            }
          }
    }

    //insert function
    BinaryTreeNode* insert(BinaryTreeNode* root,int data){
        if(search(data)){
          cout << "The element is already present in the given Binary Search Tree" << endl;
        }
        else if(root == 0){
            BinaryTreeNode* n = new BinaryTreeNode(data);
            return n;
        }
        else if(data < root->data){
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
        return root;
    }
    //search function
    BinaryTreeNode* search(BinaryTreeNode* root, int data){
        //if the tree is empty
        if(root == 0){
            return 0;
        }
        else if(data == root->data){
            return root;
        }
        else if(data < root->data){
            return search(root->left,data);
        }
        else{
            return search(root->right,data);
        }
    }

    //deleting the node
    BinaryTreeNode* remove(BinaryTreeNode* r, int data){
        BinaryTreeNode* t;
        
        if (!search(data)){
          cout << "The element you want to remove does not exist" << endl;
          return 0;
        }
        //if the root is empty
        if(r == 0){
            return 0;
        }
        //if the node is leaf node
        if(r->left == 0 && r->right == 0){
            //if only one node is present
            if(r == root){
                root = 0;
            }
            delete r;
            return 0;
        }
        //if the node is not leaf node
        if(data < r->data){
            r->left = remove(r->left,data);
        }
        else if(data > r->data){
            r->right = remove(r->right,data);
        }
        else{
            if(height(r->left) > height(r->right)){
                t = max(r->left);
                r->data = t->data;
                r->left = remove(r->left,t->data);
            }
            else{
                t = min(r->right);
                r->data = t->data;
                r->right = remove(r->right,t->data);
            }
        }
        return r;
    }
    //method to find height of the binary tree
    int height(BinaryTreeNode* r){
        int leftHeight,rightHeight;
        if(r == 0){
            return 0;
        }
        leftHeight = height(r->left);
        rightHeight = height(r->right);
        return leftHeight>rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
    //method to find minimum element of the binary tree
    BinaryTreeNode* min(BinaryTreeNode* r){
        while(r && r->left != 0){
            r = r->left;
        }
        return r;
    }

    //method to find maximum element of the binary tree
    BinaryTreeNode* max(BinaryTreeNode* r){
        while(r && r->right!= 0){
            r = r->right;
        }
        return r;
    }

};

int main(void){
    //variables.
    string lineinput;
    int input;
    int value;
    BinaryTree* binaryTree = new BinaryTree();
    
    while(true){
      //displaying the menu
      cout <<"***************************************************************"<< endl;
      cout << "                   MENU                " << endl;
      cout << "Create (0), Search (1), Breadth-First Traversal (2)" << endl;
      cout << "Depth-First Traversal: preorder (3), inorder (4), postorder (5)" << endl;
      cout << "           Delete (6), Exit Program (7)       " << endl;
      cout <<"***************************************************************"<< endl;
      //getting input from the user
      cout << "                           Choose?";
      cin >> input;
      //breaking the program if input is 7.
      if (input == 7){
        cout << "Thank you so much for using our application" << endl;
        break;
      }
      else if(input == 0){
        //flushing the input buffer. so that cin does not interfere with getline.
        cin.clear();
        fflush(stdin);
        cout << " Enter values to create:";
        getline(cin,lineinput);
        //changing string to string stream
        stringstream ss;
        ss << lineinput;
        
        //pushing all the values to binary tree.
        while(ss >> value){
            binaryTree->insert(value);
        }
        //flushing the input buffer. so that cin does not interfere with getline.
        cin.clear();
        fflush(stdin);
      }
      else if(input == 1){
        cout << "Enter value to search:";
        cin >> value;
        binaryTree->search(value) ? cout << "The element is present\n" : cout << " The element is absent\n";
      }
      else if(input == 2){
        cout << "The breadth first traversal is:";
        binaryTree->breadthFirst();
        cout << endl;
      }
      else if(input == 3){
        cout << "The preorder traversal is:";
        binaryTree->preorder();
        cout << endl;
      }
      else if(input == 4){
        cout << "The inorder traversal is:";
        binaryTree->inorder();
        cout << endl;;
      }
      else if(input == 5){
        cout << "The postorder traversal is:";
        binaryTree->postorder();
        cout <<endl;;
      }
      else if(input == 6){
          cout << "Enter value to delete:";
          cin >> value;
          binaryTree->remove(value);
      }
      else{
        cout << "Invalid output. Please check the menu" << endl;
      }  
    
    }
    return 0;
}
