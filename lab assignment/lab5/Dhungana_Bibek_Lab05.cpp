/*
AUTHOR: Bibek Dhungana
FILENAME: Dhungana_Bibek_Lab05.cpp
DATE: September 28, 2021
DESCRIPTION: This code use queue from standard template library and find the new gain/loss
            trading in the stock market in a single day.
*/

//including all the required header files.
#include <iostream>
#include <queue>
#include <string>

using namespace std;

//function prototype;
vector<string> stringTokenizer(string s);

//creating structure to store the transaction information
struct Transaction{
  int numberOfShares;
  int value;

  //default trasaction
  Transaction(){

  }
  //parameter trasaction
  Transaction(int numberOfShares, int value){
    this->numberOfShares = numberOfShares;
    this->value= value;
  }

};

//class for operation on the trasaction
class StockAccount{
private:
  //variables to store struct trasaction and capitalGain
  queue<Transaction> *q1;
  int capitalGain;
public:
  //constructor
  StockAccount(){
      //making the queue to hold the trasaction.
      q1 = new queue<Transaction>;
      //variable to store the net capital gain.
      capitalGain = 0;
  }
  //transactionBuy method
  void transactionBuy(int shareNumber,int amount){
    //creating the variable of structure trasaction
    Transaction tBuy(shareNumber, amount);

    //pushing the the trasaction into queue and displaying result
    q1->push(tBuy);
    cout << shareNumber << " share(s) bought at $" << amount << " each successfully" << endl;

  }
  //transactionSell method
  void transactionSell(int shareNumber, int amount){
    //checking is queue is empty
    if(q1->empty()){
      cout << "You have not bought any shares yet. Please, buy some shares first" << endl;
    }
    else{
      //creating the variable of structure trasaction
      shareNumber = -shareNumber;
      Transaction tSell(shareNumber, amount);

      //pushing the trasaction into the queue and displaying result
      q1->push(tSell);
      cout << -shareNumber << " share(s) sold at $" << amount << " each successfully" << endl;
    }
  }

  //status method
  void status(){
    queue<Transaction> *temp = q1;
    Transaction t;
    int initialShareAmount;
    if(!q1->empty()){
        initialShareAmount = q1->front().value;
        while(!temp->empty()){
            t = temp->front();
            temp->pop();
            capitalGain = capitalGain + (t.numberOfShares * (initialShareAmount - t.value));
        }
        cout << "The capital Gain is " << capitalGain << endl;
    }
    else{
      cout << "You have not bought any shares. Please buy some shares fisrt" << endl;
    }
  }
};

int main(){
  //string to store the user input
  string input;

  //variable to store number of share and price of each share.
  int shareNumber;
  int amount;

  //mking object of StockAccount
  StockAccount *account = new StockAccount();

  //run the program until status is entered until "exit"
  while(1){
      //getting user from the input and flusing the standard input
      cout << "****************************************************************" <<endl;
      cout << "Enter the input in following format" << endl;
      cout << "\"buy x share(s) at $y each\" or \"sell x share(s) at $y each\"" <<endl;
      cout << "Enter \"status\" to know gain or loss and \"exit\" to exit" << endl;
      cout << "****************************************************************" <<endl;
      getline(cin,input);

    //extracting the information from the input string.
    if(input.find("buy") != string::npos || input.find("sell") != string::npos){
      //coverting the string into vector of tokens
      vector<string> tokens = stringTokenizer(input);

      //using stoi function to typecast from string to integer
      shareNumber = stoi(tokens.at(1));
      amount = stoi(tokens.at(4).erase(0,1));

      //for buy option
      if(input.find("buy") != string::npos){
        account->transactionBuy(shareNumber, amount);
      }
      //s for sell option
      else{
        account->transactionSell(shareNumber, amount);
      }
      //status
    }
    else if(input.find("status") != string::npos){
      account->status();
    }
    else if(input.find("exit") != string::npos){
      cout << "Thank you for using our application. Have a nice day" << endl;
      cout << "*******************************************************" <<endl;
      break;
    }
    else{
      cout << "Invalid Input. Check the instruction." << endl;
    }
  }
    return 0;
}

/*
NAME: stringTokenizer
INPUT: string
RETURN TYPE: vector<string>
DESCRIPTION: This function takes the string, make token with respect to " " and return the vector of string.
*/
vector<string> stringTokenizer(string s){
    //variable to store vector of string
    vector<string> result;

    //dynamic mememory allocation for myString string
    char *myString = new char [s.length()+1];

    //converting c++ type string to c string for using strtok function
    strcpy (myString, s.c_str());

    //string tokenization
    char *p = strtok(myString, " ");

    while (p) {
        //converting from c string to c++ string
        string t = p;
        result.push_back(t);
        //using strtok function.
        p = strtok(NULL, " ");
    }
    return  result;
}
