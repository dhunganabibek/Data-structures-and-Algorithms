/*
 AUTHOR: BIBEK DHUNGANA
 DATE: October 28, 2021
 FILENAME:Dhungana_Bibek_Lab09.cpp
 DESCRIPTION: This code is used to find width of the binary tree for each level.
              Also, it find out the maximum width of the tree.
*/

//including the headers files.
#include <iostream>
using namespace std;

//creating class for Binary Tree Node
class BinaryTreeNode{
public:
	//instance variables
	int data;
	BinaryTreeNode *left,*right;

	//constructor of the class with default arguments
	BinaryTreeNode(int data, BinaryTreeNode* left = 0, BinaryTreeNode* right = 0){
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

//function prototypes
BinaryTreeNode* createTree();
int height(BinaryTreeNode* root);
int widthLevel(BinaryTreeNode* root, int level);
void treeWidth(BinaryTreeNode* root);


int main() {
	//creating tree using createTree function
	BinaryTreeNode *root = createTree();

	//function to find width of the binary tree
	treeWidth(root);

	return 0;
}

//function to find width of each level of the tree
int widthLevel(BinaryTreeNode* root,int level){
	//if the the tree is empty
	if(root == NULL){
		return 0;
	}
	//if the level is 1.
	if(level == 1){
		return 1;
	}
	//if the level is more than one.
	return (widthLevel(root->left,level -1) + widthLevel(root->right,level -1));
}

//function to find width of the tree
void treeWidth(BinaryTreeNode* root){
	//finding height of the tree
	int treeHeight = height(root);
	int treeWidth = 0;
	//printing value of width of each level.
	for(int i = 1; i <= treeHeight; i++){
		int widthThatLevel = widthLevel(root,i);
		cout << " The width of level " << i <<": " << widthThatLevel << endl;
		if(treeWidth < widthThatLevel){
			treeWidth =widthThatLevel;
		}
	}
	cout << " The maximum width of the tree is " << treeWidth << endl;
}

//function to find height of the tree
int height(BinaryTreeNode* root){
	//variables to store value of left and right height
	int leftHeight,rightHeight;

	//if the tree is empty
	if(root == NULL){
		return 0;
	}

	//if the tree is not empty. return max of either left tree or right tree and add 1 to it.
	leftHeight = height(root->left);
	rightHeight = height(root->right);

	//returning the height value.
	return leftHeight > rightHeight ? leftHeight+ 1 : rightHeight + 1;

}

//function to create a Tree manually.
BinaryTreeNode* createTree(){
	BinaryTreeNode* root = new BinaryTreeNode(1);
	root->left = new BinaryTreeNode(2);
	root->right = new BinaryTreeNode(3);
	root->left->left = new BinaryTreeNode(4);
	root->left->right = new BinaryTreeNode(5);
	root->right->right = new BinaryTreeNode(8);
	root->right->right->left = new BinaryTreeNode(6);
	root->right->right->left = new BinaryTreeNode(7);
	return root;


}
