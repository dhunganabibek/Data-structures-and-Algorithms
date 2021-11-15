//
//  main.cpp
//  lab6
//
//  Created by Bibek Dhungana on 10/5/21.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//class to store information of the node
class BinaryTreeNode{
public:
    BinaryTreeNode(int data){
        this->data = data;
        left = 0;
        right = 0;
        parent = 0;
    }
    char data;
    BinaryTreeNode *parent;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

int main() {
    //getting the input.
    string input;
    cout << "Enter  fully parenthesized arithmetic expression" << endl;
    getline(cin, input);
    
    //creating the stack to store the expression.
    stack<char> expression;
    
    
    
    return 0;
}
