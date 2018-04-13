#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

string units[13] = {" ", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tens[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int str2int(string str){
	int num;
	stringstream ss;
	ss<<str;
	ss>>num;

	return num;
}

int cnv13to10(string str_num){
	int len = str_num.size(), i=0;
	if( len==3 ){
		for( i=1; i<13; i++ ){
			if( tens[i]==str_num ){
				cout<<i*13<<'\n';
				break;
			}else if( units[i]==str_num ){
				cout<<i<<'\n';
				break;
			}else{
				continue;
			}
		}
	}else if( len==4 ){
		cout<<"0\n";
	}else{
		int sigma=0;
		string n1=str_num.substr(0, 3), n2=str_num.substr(4, 3);
		for( i=1; i<13; i++ ){
			if( tens[i]==n1 ){
				sigma = i*13;
				break;
			}
		}
		for( i=1; i<13; i++ ){
			if( units[i]==n2 ){
				sigma += i;
				break;
			}
		}
		cout<<sigma<<'\n';
	}
	return 0;
}

int cnv10to13(string str_num){
	int num = str2int(str_num);
	int remain=num%13, quotient=num/13;
	if( 0==remain )
		cout<<tens[quotient]<<'\n';
	else if( 0==quotient )
		cout<<units[remain]<<'\n';
	else
		cout<<tens[quotient]<<' '<<units[remain]<<'\n';
	return 0;
}

int main(){
	int n;
	string str_num, us_N;

	getline(cin, us_N);
	n = str2int(us_N);
	for( int i=0; i<n; i++ ){
		getline(cin, str_num);
		if( isdigit(str_num[0]) )
			cnv10to13(str_num);
		else
			cnv13to10(str_num);
	}
	return 0;
}

/*
4
29
5
elo nov
tam


*/
