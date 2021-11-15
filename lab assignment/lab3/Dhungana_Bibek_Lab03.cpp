/*
FILENAME: Dhungana_Bibek_Lab03.cpp
AUTHOR : BIBEK Dhungana
DATE: September 16, 2021
DESCRIPTION: The following program make use of various container present in standard template libarary.
*/

//including all the headers file.
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stdlib.h>   //for random number generation.

using namespace std;

//function prototypes
void printVectorElement(vector<int> v);
int checkRepetition(vector<int> v, int number);
vector<int> mergeVector(vector<int> v1, vector<int> v2);

//start of main function
int main(){

  //Question number 1
  //creating arr1 and populate with 10 interger values.
  array<int,10> arr1 = {1,2,3,4,5,6,7,8,9,10};

  //creating arr2 and populate it with value 5 for all elements.
  array<int,10> arr2;
  arr2.fill(5);

  //printing the first and last element of arr1
  cout << "The first element of arr1 is " << arr1.front() << endl;
  cout << "The last element of arr1 is " << arr2.back() << endl;

  //swap the value of arr1 and arr2
  arr1.swap(arr2);
  cout << "The element of arr1 and arr2 is successfully swapped." << endl;

  //printing the size of the arrays
  cout << "The size of arr1 is " << arr1.size() << endl;
  cout << "The size of arr2 is " << arr2.size() << endl;
  //end of question 1

  //question number 2.. Part a
  cout << "End of Problem 1." << endl;
  cout << "**************************************************************\n"<< endl;


  //defining all the required variables.
  int elementNumbers;

  //creating two vectors of intergers.
  vector<int> unsortedVector;
  vector<int> sortedVector;

  //asking the number of elements n vector from the user
  cout << "How many element do you want in the vector:";
  cin >> elementNumbers;

  //populating the elements in vector with user input:
  for(int i = 0; i< elementNumbers; ++i){
    int element;
    cout << "Enter element " << i <<":";
    cin >> element;
    unsortedVector.push_back(element);
  }

  //copying all the element of one vector into another
  //equal operator (=) in vector class is overloaded for copying vector.
  sortedVector = unsortedVector;

  //sorting the sorted vector using sort function
  // can also use any other sort techniques.
  sort(sortedVector.begin(),sortedVector.end());

  //Displaying all the element of the sorted vector.
  cout << "The element in the sorted vector are:" << endl;
  vector<int> :: iterator i1;
  for(i1 = sortedVector.begin(); i1 != sortedVector.end(); i1++){
    cout << *i1 << " ";
  }
  cout << endl;

  //Displaying all the element of the sorted vector.
  cout << "The element in the unsorted vector are:" << endl;
  vector<int> :: iterator i2;
  for(i2 = unsortedVector.begin(); i2 != unsortedVector.end(); i2++){
    cout << *i2 << " ";
  }
  cout << endl;

  cout << "**************************************************************\n"<< endl;

  //Question 2 . Part b
  //creating vector v1 and populating with 100 elements.
  vector<int> v1;
  for(int i = 5; i <= 105; i++){
    v1.push_back(i);
  }
  //creating vector v2 and populating with 10 elements.
  vector<int> v2;
  for(int i = 0; i <= 10; i++){
    v2.push_back(i);
  }
  //finding how many element of v1 is present in v2.
  vector<int> commonElement;
  for(int i = 0 ; i < v1.size();i++){
    for(int j = 0; j < v2.size(); j++){
      if (v2.at(j) == v1.at(i)){
        commonElement.push_back(v2.at(j));
      }
    }
  }
  //printing element present in both teh vectors.
  cout << "The element present in both vector are:";
  for(int i = 0; i < commonElement.size(); i++){
    cout << commonElement.at(i) << " ";
  }
  cout << endl;

  //calculatin and printing how many elements of one vector is contained in another vector.
  double percentPresent = ((double)(commonElement.size())/v1.size())*100;
  cout << "The percentage of element present in container is:" << percentPresent << endl;
  cout << "The percentage of elemnt not present in the conatainer is " << 100 - percentPresent << endl;

  cout << "**************************************************************\n"<< endl;

  //Question 2. part c
  //creating two vector of some arbitary size.
  vector<int> test1;
  vector<int> test2;
  for (int i = 0; i < rand()%10; i++){
    test1.push_back(rand()%10);
    test2.push_back(rand()%10);

  }
  //checking if two vector are equal
  if(test1 == test2){
    cout << "The vector are equal" << endl;
  }
  else{
    cout << "The vector are not equal" << endl;
  }

  cout << "**************************************************************\n"<< endl;

  //Question 2. Part d
  //generating random number
  int randomSize = (10 + rand()%50);
  vector<int> v4;
  for(int i = 0; i < randomSize;i++){
    v4.push_back(rand()%5);
  }
  //The number that should be checked for repetition
  int number = 3;


  //using that function to check number of repetation
  int repeatedAmount = checkRepetition(v4,number);
  cout << "The number " << number << " is repeated " << repeatedAmount <<" times" <<endl;

  cout << "**************************************************************\n"<< endl;


  //Question 2. Part e;
  //creating two vector of size 7
  //creating random number from 5 to 10.
  int randomNumber = 5 + rand()%6;

  //creating two vector
  vector<int> vector1;
  vector<int> vector2;

  //populating vector with random number from 1 to 10
  for(int i = 0; i < randomNumber;i++){
    vector1.push_back(rand()%10);
    vector2.push_back(rand()%10);
  }

  //sorting both of these vectors.
  sort(vector1.begin(),vector1.end());
  sort(vector2.begin(),vector2.end());

  vector<int> sortedFinalVector = mergeVector(vector1, vector2);

  //printing the element of vectors.
  cout << "The element of first vector are:" << endl;
  printVectorElement(vector1);

  cout << "The element of second vector are:" << endl;
  printVectorElement(vector2);

  cout << "The element of merged vector are:" << endl;
  printVectorElement(sortedFinalVector);

  cout << "**************************************************************\n"<< endl;

  return 0;
}
/*
NAME: printVectorElement
INPUT ARGUMENTS: vector<int>
RETURN TYPE: void
DESCRIPTION: This function print element of the vector in the console.
*/
void printVectorElement(vector<int> v){
  for(int i = 0 ; i < v.size(); i++){
    cout << v.at(i) << " ";
  }
  cout << endl;
}

/*
NAME: mergeVector
INPUT ARGUMENTS: vector<int>,vector<int>
RETURN TYPE: vector<int>
DESCRIPTION: This function take two interger vector as argumants and return merged vector as
             return type.
*/
vector<int> mergeVector(vector<int> v1, vector<int> v2){
  vector<int> v;
  v.insert(v.end(), v1.begin(), v1.end());
  v.insert(v.end(), v2.begin(), v2.end());
  //sorting the vector
  sort(v.begin(), v.end());
  return v;
}

/*
NAME:checkRepetition
INPUT ARGUMENTS:vector<int>, int
RETURN TYPE: int
DESCRIPTION: This functio takes vector<int> and int as input and return the number of counter of int in that vector.
*/
//function to check the repetation number of element in the vector.
int checkRepetition(vector<int> v, int number){
  int count = 0;
  for (int i = 0; i < v.size(); i++){
    if (number == v.at(i)){
      count++;
    }
  }
  return count;
}
