/*
AUTHOR: Bibek Dhungana
FILENAME: Dhungana_Bibek_lab8.cpp
DATE:October 21, 2021
DESCRIPTION: This code is used to check if the given tree is binary tree or not.
             It also check if the given tree is balanced.
*/
//including headers file.
#include  <iostream>

using namespace std;

//class for the binary tree node
class BinaryTreeNode{
public:
	//instance variables
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

//function prototypes.
bool isBinarySearchTree(BinaryTreeNode* r);
bool isBalanced(BinaryTreeNode* r);
int height(BinaryTreeNode* r);
int balanceFactor(BinaryTreeNode* r);
int maximumValue(BinaryTreeNode* r);
int mininumValue(BinaryTreeNode* r);


int main(){
	//variable to store the root of the binary tree
	BinaryTreeNode* root = new BinaryTreeNode(4);

	//manually building a binary tree
	root->left = new BinaryTreeNode(2);
	root->right = new BinaryTreeNode(5);
	root->left->left = new BinaryTreeNode(1);
	root->left->right = new BinaryTreeNode(3);



	// checking if the binary tree is binary search tree
	if(isBinarySearchTree(root)){
		cout << "The given tree is binary search tree" << endl;
	}
	else{
		cout << "The given tree is not binary search tree" << endl;
	}

	//checking if the tree is balanced
	if (isBalanced(root)){
		cout << "The binary tree is balanced" << endl;
	}
	else{
		cout << "The binary tree is not balanced" << endl;
	}

	return 0;

}

//function to check if the given binary tree is binary search tree.
bool isBinarySearchTree(BinaryTreeNode* r){
	//if the tree is empty
	if(r == 0){
		return true;
	}
	//checking if parent node is greater than left child
	if(r->left != 0 && maximumValue(r->left) >= r->data ){
		return false;
	}

	//checking if the parent node is smaller than right child
	if(r->right != 0 && mininumValue(r->right) <= r->data){
		return false;
	}

	//running all the case recursively for left subtreee
	if(isBinarySearchTree(r->left) != true){
		return false;
	}
	//running the case recursively for right subtree.
	if (isBinarySearchTree(r->right) != true){
		return false;
	}
	// if every node pass the test.
	return true;
}

//function to check if the tree is balanced.
bool isBalanced(BinaryTreeNode* r){
	//if balance factor of all thee node is -1, 0  or 1.
	if(r == 0){
		return true;
	}
	int bf = balanceFactor(r);
	if ((bf == 1 || bf == -1 || bf == 0) && isBalanced(r->left) && isBalanced(r->right)){
		return true;
	}
	return false;
}

//function to calculate the height of the tree
int height(BinaryTreeNode* r){

	//variable to store height of left and right child height
	int leftChildHeight;
	int rightChildHeight;

	//if the tree is empty.
	if (r == 0){
		return 0;
	}
	//calculating the leftchildheight and rightChild height by recursively.
	leftChildHeight = height(r->left);
	rightChildHeight = height(r->right);

	return leftChildHeight > rightChildHeight ? (leftChildHeight + 1) : (rightChildHeight + 1);

}

//function to find the balanced factor
int balanceFactor(BinaryTreeNode* r){
	if(r == 0){
		return 0;
	}
	return height(r->left) - height(r->right);
}

//function to find  maximumValue of the tree.
int maximumValue(BinaryTreeNode* r){

	while(r->right != 0){
		r = r->right;
	}
	return r->data;

}

//function to find mininumValue of the binary tree.
int mininumValue(BinaryTreeNode* r){
	while(r->left != 0){
		r = r->left;
	}
	return r->data;
}
