//including all the required libararies
#include <iostream>

using namespace std;

//declaring all the function prototype
void printHelloWorld();
void averageTwoNumber();
int sumInteger(int);
int factorial(int);
double arraySum();

int main(){
	
	//call printHelloWorld Function
	cout << endl;
	printHelloWorld();
	cout << "\n" << endl;

	//calling the function averageTwoNumber
	averageTwoNumber();
	cout << "\n" << endl;

	//calling sumInteger function
	int inputForSum;
	cout << "Enter the number upto which you want to compute sum:";
	cin >> inputForSum;
	cout << "The sum of all whole number is " << sumInteger(inputForSum) << "\n\n";

	//calling factorial Function
	int num;
	cout << "Enter the number to calculate factorial of:";
	cin >> num;
	cout << "The factorial of number " << num << " is " << factorial(num) << "\n\n";

	//calling the printArraySum Function
 	double result = arraySum();
	cout << "The sum of element in the array is " << result << "\n\n";


	return 0;
}

/*
NAME: printHelloWorld
INPUT: void
RETURN TYPE: void
DESCRIPTION: This function print Hello, World! to the console.
*/
void printHelloWorld(){
	cout << "Hello, World!" << endl;
}

/*
NAME: averageTwoNumber
INPUT: void
RETURN TYPE: void
DESCRIPTION: This function take two input from the user and print average of these two numbers.
*/
void averageTwoNumber(){
	double num1,num2,average;

	//asking input from the user
	cout << "Enter first number:";
	cin >> num1;

	//asking input from the user
	cout << "Enter second number:";
	cin >> num2;

	//calculating and printing the average
	cout << "The average of "<< num1 << " and " << num2 << " is " << (num1+num2)/2 << endl;
}

/*
NAME:sumInteger
INPUT:int
RETURN TYPE:int
DESCRIPTION: This function ask for the input and find the sum upto that number
*/
int sumInteger(int num){
	int sum = 0;
  for(int i = 0; i <= num; i++){
		sum = sum + i;
	}
	return sum;
}

/*
NAME:factorial
INPUT:void
RETURN TYPE: input
DESCRIPTION: This function ask the user for the input and calculate the factorial.
*/
int factorial(int num){
	int result = 1;

	//calculating the factorial
	for(int i = 1; i <= num; i++){
		result = result * i;
	}
	return result;
}

/*
NAME:printArraySum
INPUT:void
RETURN TYPE:void
DESCRIPTION: This function ask user to enter 5 number separated by space, store it in array and
             print the sum of the array.
*/
double arraySum(){
	double num[5];
	double sum = 0.0;

	//asking for input.
	cout << "Enter five number:";
	for(int i = 0; i < 5; ++i){
		cin >> num[i];
	}

	//calculating the sum
	for(int i = 0; i < 5; ++i){
		sum = sum + num[i];
	}
	return sum;
}
