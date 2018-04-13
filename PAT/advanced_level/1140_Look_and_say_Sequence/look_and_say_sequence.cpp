// #pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string num2str(int num){
	stringstream ss;
	string str;
	ss<<num;
	ss>>str;
	return str;
}

string updateS(string s){
	int len = s.size();
	string newstr = "";
	char ch = s[0];
	int i = 0;
	int pos = 0;
	for( int i = 0; i < len; i++){
		while( s[i] == ch ){
			i++;
		}
		newstr += ch;
		newstr += num2str(i - pos);
		pos = i;
		ch = s[i--];
	}
	return newstr;
}

int main(){
	string s;
	int n;

	cin>>s>>n;

	for( int i = 1; i < n; i++ ){
		s = updateS(s);
	}

	cout<<s<<'\n';
}