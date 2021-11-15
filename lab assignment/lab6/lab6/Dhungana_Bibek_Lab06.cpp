/*
 AUTHOR: Bibek Dhungana
 FILENAME: Dhungana_Bibek_Lab06.cpp
 DATE: October 10, 2021
 DESCRIPTION: This program construct the expression tree for the given arithmatic expression and find the value of the expression
              using expression tree.
 */

//including all the required headers file.
#include <iostream>
#include <stack>
#include <string>
#include <cmath>     //for pow() function in ^ operator.

using namespace std;

//defining the class for TreeNode
class Node{
public:
	//variables
	char data;
	Node* left;
	Node* right;

	//constructor
	Node(char data){
		this->data = data;
		this->left = 0;
		this->right = 0;
	}

	//overloaded construtor
	Node(char data, Node* left, Node* right){
		this->data = data;
		this->left = left;
		this->right = right;
	}
};


//function prototypes.
bool isDigit(char c);
bool isRightOperator(char c);
bool isExpressionValid(string input);
int precedence(char c);
string infixToPostfix(string s);
void inorder(Node* T);
void preorder(Node* T);
void postorder(Node* T);
Node* constructExpressionTree(string s);
int evaluateExpressionTree(Node* root);
void print2DExpressionTree(Node* r, unsigned int space);



int main(){
    //root of expression tree
	Node* expressionTree = 0;

	//asking for input
	string input;
	cout << "Enter the expression:";
	getline(cin, input);

	//checking if the input operation only contains valid charcaters.
	if(!isExpressionValid(input)){
		cout << "Expression can only contains digits, operators(%,^,+,-, /, *) and parenthesis()." << endl;
	}
	//if only valid characters are present.
	else{
		//converting input expression to postfixexpression.
		string postfixExpression = infixToPostfix(input);

		//constructing the expression tree using postfixExpression
		expressionTree = constructExpressionTree(postfixExpression);

		//displaying the result of inorder traversal
		cout << "\nThe inorder traversal of the given expression tree is:";
		inorder(expressionTree);

		//displaying the result of preorder traversal
		cout << "\nThe preorder traversal of the given expression tree is:";
		preorder(expressionTree);

		//displaying the result of postorder traversal
		cout << "\nThe postorder traversal of the given expression tree is:";
		postorder(expressionTree);

		//finding the value of the expression tree
		cout << "\nThe value associated with root is " << evaluateExpressionTree(expressionTree);

		//printing the expression tree
		cout << "\nThe expression tree produced is:";
		cout << "\n*********** Horizontal Expression Tree********************" << endl;
		print2DExpressionTree(expressionTree, 15);
		cout << "\n**********************************************************" << endl;

	}
	return 0;
}

/*
 NAME:isExpressionValid
 INPUT: string
 RETURN TYPE: bool
 DESCRIPTION: This function takes the string as input and return true of the input only contains
              digits, operators and parenthesis().

 */
bool isExpressionValid(string input){
	bool result;
	for(unsigned int i = 0; i < input.length(); i++){
		if (isDigit(input.at(i)) || isRightOperator(input.at(i)) || input.at(i) == '(' || input.at(i) == ')'){
			result = true;
		}
		else{
			result = false;
			break;
		}
	}
	return result;
}

/*
 NAME: isDigit
 INPUT: char
 RETURN TYPE: bool
 DESCRIPTION: This function takes character as input and return true if the character is digit.
              else, the function return false;
 */
bool isDigit(char c){
	if (c >= '0' && c <= '9'){
		return 1;
	}else{
		return 0;
	}
}

/*
 NAME:isOperator
 INPUT: char
 RETURN TYPE:bool
 DESCRIPTION: This function takes charcter and return true if the character is right operator.(+, -, *, /,%,^).
              return false otherwise.
 */
bool isRightOperator(char c){
	if( c == '*' || c == '/' || c == '+' || c == '-' || c == '^' || c == '%' || c == ' '){
		return true;
	}
	return false;
}

/*
 NAME:precedence
 INPUT: char
 RETURN TYPE: int
 DESCRIPTION: This function take the character input and return the precedence value for each operator.
 */
int precedence(char c){
	if (c == '^'){
		return 3;
	}
	else if(c == '/' || c == '*'){
		return 2;
	}
	else if (c == '+' || c == '-'){
		return 1;
	}
	else{
		return -1;
	}
}

/*
 NAME:infixToPostfix
 INPUT: string
 RETURN TYPE: string
 DESCRIPTION: This function take regular(infix) arithmatic expression and convert it into postfix expression and return it.
 */
string infixToPostfix(string s){

	//creating the char stack.
	stack<char> st;

	//result string of postfix expression.
	string result;

	//looping each character of the input string
	for(unsigned int i = 0; i < s.length(); i++){
		char c = s[i];

		//if the character is space,skip that iteration.
		if(c == ' '){
			continue;
		}
		//if the character is digit.
		else if(isDigit(c)){
         	 result += c;
        }
		//if the character is '(', push it into the stack.
		else if(c == '('){
			st.push('(');
		}
		//if the character is ), pop all the output until ( is encountered.
		else if(c == ')'){
			while(st.top() != '('){
				result += st.top();
				st.pop();
			}
			//popping '(' from the stack.
			st.pop();
		}
		//if the operator is encountered.
		else{
			while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	//pop all the remaining stuff from the stack
	while(!st.empty()){
		result += st.top();
		st.pop();
	}

	return result;
}

/*
 NAME:constructExpressionTree
 INPUT: string
 RETURN TYPE: Node*
 DESCRIPTION: This function takes postfix expression, contruct the expression tree based on it ans return the pointer
              to root of that expression tree.
 */
Node* constructExpressionTree(string s){
	//creating the empty stack to store the store pointer of the expression tree.
	stack<Node*> stack;

	//looping the each characters.
	for(unsigned int i = 0; i < s.length(); i++){
		char c = s.at(i);

		//is the character is operator
		if(isRightOperator(c)){
			//pop top node from the stack
			Node* n1 = stack.top();
			stack.pop();

			//poping the top node again
			Node* n2 = stack.top();
			stack.pop();

			//construct a new binary tree with given operator and two child node.
			Node* node = new Node(c,n2, n1);

			//push the current node into the stack
			stack.push(node);
		}
		//if the given character is numbers, create a binary tree and push it into the stack.
		else{
			stack.push(new Node(c));
		}
	}
	//return pointer to root of expression tree of that stack
	Node* root = stack.top();
	return root;
}

/*
 NAME:inorder
 INPUT:Node*
 RETURN TYPE:void
 DESCRIPTION: perform inorder traversal of the expression tree.
 */
void inorder(Node* T){
	if (T != NULL) {
		inorder(T->left);
		cout << T->data << " ";
		inorder(T->right);
	}
}

/*
 NAME:preorder
 INPUT:Node*
 RETURN TYPE:void
 DESCRIPTION: perform preorder traversal of the expression tree.
 */
void preorder(Node* T){
	if (T != NULL) {
		cout << T->data << " ";
		inorder(T->left);
		inorder(T->right);
	}
}

/*
 NAME:postorder
 INPUT:Node*
 RETURN TYPE:void
 DESCRIPTION: perform postorder traversal of the expression tree.
 */
void postorder(Node* T){
	if (T != NULL) {
		inorder(T->left);
		inorder(T->right);
		cout << T->data << " ";
	}
}


/*
 NAME:evaluateExpressionTree
 INPUT:Node*
 RETURN TYPE:int
 DESCRIPTION: This fucntion takes pointer to root of expression tree as input and return the evaluation expression based of that
              expression tree.
 */
int evaluateExpressionTree(Node* root)
{
    //if the tree is empty
    if (!root)
        return 0;

    //if leaves nodes.
    if (!root->left && !root->right){
    	 return root->data - '0';
    }
    //evaluating the left subtree
    int leftValue = evaluateExpressionTree(root->left);

    //evaluating the right subtree
    int rightValue = evaluateExpressionTree(root->right);

    // checking which operatr can be applied.
    if (root->data == '+')
        return leftValue + rightValue;
    if (root->data == '-')
        return leftValue - rightValue;
    if (root->data == '*')
        return leftValue * rightValue;
    if (root->data == '/')
    	return leftValue / rightValue;
    if (root->data == '^')
    	return pow(leftValue, rightValue);
    if (root->data == '%')
    	return leftValue % rightValue;
    else{
    	return 0;
    }


}

/*
 NAME:print2DExpression Tree
 INPUT:Node*
 RETURN TYPE:void
 DESCRIPTION: This function print the expressiion tree horizontally in 2D space
 */
void print2DExpressionTree(Node* r, unsigned int space){
	unsigned int initialSpace = 5;
	if(r == 0){
		return;
	}
	space = initialSpace + space;
	print2DExpressionTree(r->left,space);
	cout << endl;
	for(unsigned int i = initialSpace;i<space;i++){
		cout << " ";
	}
	cout << r->data << " ";
	print2DExpressionTree(r->right,space);
}
