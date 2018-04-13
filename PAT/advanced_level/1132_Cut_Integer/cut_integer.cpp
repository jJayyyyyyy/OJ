#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int string2num(string s){
	stringstream ss;
	ss<<s;
	int num;
	ss>>num;
	return num;
}

int main(){
	int n;
	cin>>n;
	for( int i = 0; i < n; ++i ){
		string s;
		cin>>s;
		int len = s.size();
		string s1 = s.substr(0, len/2);
		string s2 = s.substr(len/2, len/2);
		int n0 = string2num(s);
		int n1 = string2num(s1);
		int n2 = string2num(s2);
		if( n1 == 0 || n2 == 0 ){
			cout<<"No\n";
		}else if( n0 % (n1 * n2) == 0 ){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}

	return 0;
}