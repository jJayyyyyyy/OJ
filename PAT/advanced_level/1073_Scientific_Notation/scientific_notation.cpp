#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int str2num(string str){
	int num;
	stringstream ss;
	ss<<str;
	ss>>num;
	return num;
}

string slice(string s, int begin, int end=-1){
	if( -1!=end )
		return s.substr(begin, end - begin);
	else
		return s.substr(begin);
}

string nString(char ch, int n){
	string s(n, ch);
	return s;
}

int main(){
	string sci;
	cin>>sci;
	int ixE = sci.find('E');

	if( '-'==sci[0] )
		cout<<'-';

	char part1 = sci[1];
	string part2 = slice(sci, 3, ixE);
	int len2 = ixE-3;
	int e = str2num( slice(sci, ixE+1) );

	if( e>0 ){
		if( e<len2 ){
			cout<<part1 + slice(part2, 0, e) + '.' + slice(part2, e, len2);
		}else{
			cout<<part1 + part2 + nString('0', e-len2);
		}
	}else if( e==0 ){
		cout<<slice( sci, 1, ixE );
	}else{
		e = -e;
		cout<<"0." + nString('0', e-1) + part1 + part2;
	}

	return 0;
}
/*
+1.23400E-03

-1.2E+10


0.00123400
-12000000000

*/
