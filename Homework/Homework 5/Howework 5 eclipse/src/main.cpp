#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while(!s.isEmpty()){
		cout << s.top();
		s.pop();
		cout <<"\n";
	}





	return 0;
}
