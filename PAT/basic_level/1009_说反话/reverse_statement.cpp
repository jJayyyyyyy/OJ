#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main(){
	stack<string> str_stack;
	string us_str, sub_str;

	getline(cin, us_str);
	stringstream ss(us_str);

	while( !ss.eof() ){
		getline(ss, sub_str, ' ');
		str_stack.push(sub_str);
	}

	cout<<str_stack.top();
	str_stack.pop();
	while(!str_stack.empty()){
		cout<<' '<<str_stack.top();
		str_stack.pop();
	}

	return 0;
}
