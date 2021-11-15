/*
AUTHOR: Bibek Dhungana
FILENAME: Dhungana_Bibek_Lab04.cpp
DATE: September 23, 2021
DESCRIPTION:  The first part of the program checks if the the given word is pallindrome and
              the second part of the program tokenize the ip address.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//function prototypes
void isPalindrome(string);
vector<string> ipAddressTokenizer(string ip,string delimitor = ".");

int main() {

    //question 1.
    //initialiazing the variables.
    string input1;                     //string for checking palindrome.

    //getting input from the user.
    cout << "Enter the string to check if it is Palindrome:";
    getline(cin,input1);

    //calling the palindrome function.
    isPalindrome(input1);

    cout << "****************************************************" << endl;

    //Question 2
    //initializing the required variables.
    vector <string> tokenizedString;   //vector of tokenized string.
    string input2;                     //input for string tokenization.

    //getting input from the user.
    cout << "Enter the IP address to tokenize:";
    getline(cin, input2);

    //calling the ipAddressTokenizer function.
    tokenizedString =  ipAddressTokenizer(input2);

    //printing the element of tokenized string
    cout << "The tokennized String are: " << endl;
    cout << "{";
    for(int i = 0; i < tokenizedString.size() -1 ; i++){
        cout << tokenizedString.at(i) << ",";
    }
    cout << tokenizedString.at(tokenizedString.size()- 1);
    cout << "}" << endl;
    cout << "****************************************************" << endl;
}

/*
 NAME:isPalindrome
 INPUT:string
 RETURN TYPE: void
 DESCRIPTION: This function takes string as a input ans  chevk if the string is pallindrome Palindrome
              and display the result to the user.
 */
void isPalindrome(string s){
    //initializing the required variables.
    string reverseString = "";
    string::reverse_iterator itr;
    string::iterator it;

    //iterating the element of the of original string from back and forming the new strinbg with reverse element.
    for(itr = s.rbegin(); itr != s.rend(); itr++){
        if(*itr != ' '){
            reverseString.push_back(*itr);
        }
    }

    //removing space from the original string
    string sWithoutSpace ;
    for(it = s.begin(); it != s.end(); it++){
        if (*it != ' '){
            sWithoutSpace.push_back(*it);
        }
    }

    //checking if the string are equal
    if (sWithoutSpace.compare(reverseString) == 0){
        cout << s << endl;
        cout << reverseString << endl;
        cout << "strings are palindrome" << endl;
    }

    //if the string are not equal
    else{
        cout << s << endl;
        cout << reverseString << endl;
    }
}

/*
 NAME: ipAddressTokenizer
 INPUT:string ip, String delimitor
 RETURN TYPE:void
 DESCRIPTION:ipAddressTokenizer
 */
vector<string> ipAddressTokenizer(string ip,string delimitor){
    //initializing the variables.
    vector<string> tokenizedString;
    string s;

   //tokenizing the string
    while(true){
        //intializing the varibles.
        int start = 0;
        int end = ip.find(delimitor);

        //creating token and pushing back to vector.
        s = ip.substr(start,end - start);
        tokenizedString.push_back(s);

        //updating the string.
        ip = ip.substr(end + 1);

        //if the delimitor is not found, break the loop.
        if (end == string::npos){
            break;
        }
    }
    return tokenizedString;
}
