//including all the required headers.
#include <iostream>

using namespace std;

//defining the class Student
class Student{
private:
  //intializing all the required variables.
  int admno;
  string sname;             //we can also store sname in charater array.
  float eng,math,science;
  float total;
  /*
  NAME: ctotal
  INPUT: void
  RETURN TYPE: float
  DESCRIPTION: private function to calculate total marks of eng, math and science.
  */
  float ctotal(){
    return eng + math + science;
  }
public:
  /*
  NAME: takeData
  INPUT: void
  RETURN TYPE: void
  DESCRIPTION: function to input information about student
  */
  void takeData(){
    cout << "Enter admission number: ";
    cin >> admno;

    //flushing the standard input as getline and cin work differently.
    cin.clear();
    fflush(stdin);
    
    //using getline functio to take complete student name
    cout << "Enter student name: ";
    getline(cin,sname);

    cout << "Enter Engineering number:";
    cin >> eng;

    cout << "Enter Math number: ";
    cin >> math;

    cout << "Enter science number: ";
    cin >> science;
    
    //calling total function to calculate totall marks of eng, math and science.
    total = ctotal();

  }
  /*
  NAME: showData
  INPUT: void
  RETURN TYPE: void
  DESCRIPTION: function to display information about the student.
  */
  void showData(){
    cout << "**********************************************" <<endl;
    cout << "The student information are:"<< endl;
    cout << "Student Admission Number:" << admno << endl;
    cout << "Student Name:" << sname << endl;
    cout << "Engineering Number:" << eng << endl;
    cout << "Math Number:" << math << endl;
    cout << "Science Number:" << science << endl;
    cout << "Student class total is " << total << endl;
    cout << "**********************************************" <<endl;
  }


};

//defining the class BOOK
class BOOK{
private:
  int BOOKNO;
  string BOOKTITLE;    //we can also define BOOKTITLE using character array.
  float PRICE;
  
  /*
  NAME: TOTAL_COST
  INPUT: int
  RETURN TYPE: float
  DESCRIPTION: function to calculate price for N number of books, where n is passed as argument.
  */
  float TOTAL_COST(int N){
    return N * PRICE;
  }
  
public:
  /*
  NAME: INPUT
  INPUT: void
  RETURN TYPE: void
  DESCRIPTION: function to get information about the BOOK.
  */
  void INPUT(){
    cout << "Enter Book number: ";
    cin >> BOOKNO;
    
    //flusing the std input since cin and getline may interfere with input buffer.
    cin.clear();
    fflush(stdin);
    
    cout << "Enter Book title: ";
    getline(cin,BOOKTITLE);
    
    //flusing the std input since cin and getline may interfere with input buffer.
    cin.clear();
    fflush(stdin);

    cout << "Enter Book Price: ";
    cin >> PRICE;
   }
   
    
   /*
   NAME: PURCHASE
   INPUT: void
   RETURN TYPE: void
   DESCRIPTION: function to calculate total cost for n copies of the book and printing the result.
   */
    void PURCHASE(){
      int number;
      cout << "How many copy you want to purchase?";
      cin >> number;
      cout << "Your total due amount is " << TOTAL_COST(number) << endl;
      cout << "**********************************************" <<endl;
    }


};




//defining the class Distance
class Distance{
private:
  int feet;
  float inches;
public:
  /*
  NAME: set
  INPUT: (int,float)
  RETURN TYPE: void
  DESCRIPTION: This fucnction takes input in feet and inches.
  */
  void set(int feet, float inches){
    this->feet = feet;
    this->inches = inches;
  }
  
  /*
  NAME: disp
  INPUT: void
  RETURN TYPE: void
  DESCRIPTION: This fucnction print the distance information of feet and inches in console.
  */
  void disp(){
    cout << "Distance: " << feet << " feet " << "and " << inches << " inches" << endl;
  }
  
  /*
  NAME: add
  INPUT: Disatance
  RETURN TYPE: Distance
  DESCRIPTION: This fucnction calculate the sum of two distances and return the Distance object.
  */
  Distance add(Distance d){
    Distance sum;
    sum.feet = this->feet + d.feet;
    sum.inches = this->inches + d.inches;
    
    //converting inches to 1 feet if inches >= 12.(1 feet = 12 inches).
    //We could simply display in inches, but converting inches greater than 12 into feet make output more readable.
    while(sum.inches >= 12){
      if(sum.inches >= 12){
        sum.inches = sum.inches - 12.0;
        sum.feet++;
      }
   }
    return sum;
    
  }
  
};

//main function.
int main(int argc, char* argv[]){

  //making object of Student class, taking input and showing output
  Student student1;
  student1.takeData();
  student1.showData();

  //making object of Book class.
  BOOK b1;
  b1.INPUT();
  b1.PURCHASE();

 //making use of distance class.
 //making three distance object.
 Distance d1,d2,d3;
 
 //setting value and calculating sum of two distances and assigning to d3.
 d1.set(1,2.2);
 d2.set(3,4.1);
 d3 = d1.add(d2);
 
//displaying all the distances.
d1.disp();
d2.disp();
cout << "The sum of two distances is given below:" << endl;
d3.disp();


return 0;
}


