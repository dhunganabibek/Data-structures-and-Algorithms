/*
 AUTHOR:Bibek Dhungana
 Date: October 14, 2021
 FILENAME:Dhungana_Bibek_Lab07.cpp
 Description: This code make a binary tree and invert the given binary tree.
 */

//including the headers files.
#include <iostream>
#include <queue>

using namespace std;

//creating a class to store the BinaryTreeNode
class BinaryTreeNode{
public:
    //variables.
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    //constructor
    BinaryTreeNode(int data, BinaryTreeNode* left = 0, BinaryTreeNode* right = 0){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

//function prototype
void inorder(BinaryTreeNode* root);
void preorder(BinaryTreeNode* root);
void postorder(BinaryTreeNode* root);
void mirrorBinaryTree(BinaryTreeNode* root);
void breadthFirstTraversal(BinaryTreeNode* root);

//main function
int main() {
    //making a tree
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);

    //preorder traversal of the original tree
    cout << "\nThe preorder traversal of the original tree is ";
    preorder(root);
    //inorder traversal of the original tree
    cout << "\nThe inorder traversal of the original tree is ";
    inorder(root);
    //postorder traversal of the original tree
    cout << "\nThe post order traversal of the original tree is ";
    postorder(root);
    //level oreder traversal of the original tree
    cout << "\nThe level order traversal of the original tree is ";
    breadthFirstTraversal(root);

    cout << "\n\n*****************************************************************\n";
    //calling mirror binaryTree function
    mirrorBinaryTree(root);

    //preorder traversal of the mirrored tree
    cout << "\nThe preorder traversal of the mirrored tree is ";
    preorder(root);
    //inorder traversal of mirrored tree
    cout << "\nThe inorder traversal of the mirrored tree is ";
    inorder(root);
    //postorder traversal of the mirrored tree
    cout << "\nThe post order traversal of the mirrored tree is ";
    postorder(root);
    //level order traversal of the mirrored tree
    cout << "\nThe level order traversal of the mirrored tree is ";
    breadthFirstTraversal(root);
    cout << endl;
    return 0;
}

/*
 NAME:inorder
 INPUT:BinaryTreeNode*
 RETURN TYPE:void
 DESCRIPTION: function for inorder traversal
 */
void inorder(BinaryTreeNode* root){
    //if the tree is empty.
    if(root == 0){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/*
 NAME:postorder
 INPUT:BinaryTreeNode*
 RETURN TYPE:void
 DESCRIPTION: function for postorder traversal
 */
void postorder(BinaryTreeNode* root){
    //if the the tree is empty
    if(root == 0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/*
 NAME:preorder
 INPUT:BinaryTreeNode*
 RETURN TYPE:void
 DESCRIPTION: function for preorder traversal
 */
void preorder(BinaryTreeNode* root){
    //if the tree is empty
    if(root == 0){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/*
 NAME:mirrorBinaryTree
 INPUT:BinaryTreeNode*
 RETURN TYPE:void
 DESCRIPTION: function for mirriring the binary tree.
 */
void mirrorBinaryTree(BinaryTreeNode* root){
    //temp variable
    BinaryTreeNode* temp;

    //if the root is empty
    if(root == 0){
        return;
    }

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    //swaping the tree
    temp = root->right;
    root->right = root->left;
    root->left = temp;
}

/*
 NAME:breadthFirstTraversal
 INPUT:BinaryTreeNode*
 RETURN TYPE:void
 DESCRIPTION: function for breadthFirst traversal
 */
void breadthFirstTraversal(BinaryTreeNode* root){
    queue<BinaryTreeNode*> myqueue;
    myqueue.push(root);
    while(myqueue.empty() == false){
        BinaryTreeNode* node = myqueue.front();
        cout << node->data << " ";
        myqueue.pop();

        if(node->left != 0){
            myqueue.push(node->left);
        }
        if(node->right != 0){
            myqueue.push(node->right);
        }
    }
}
