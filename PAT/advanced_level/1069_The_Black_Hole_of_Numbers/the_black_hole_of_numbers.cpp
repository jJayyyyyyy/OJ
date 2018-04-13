#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int fillPreZero(string &str){
	int len = 4 - str.size();
	string zero(len, '0');
	str = zero + str;
	return 0;
}

int str2num(const string &str){
	stringstream ss(str);
	int num;
	ss>>num;
	return num;
}

string num2str(int num){
	stringstream ss;
	string str;
	ss<<num;
	ss>>str;
	fillPreZero(str);
	return str;
}

int isSame(const string &str){
	if(str[0]==str[1] && str[1]==str[2] && str[2]==str[3]){
		return 1;
	}else{
		return 0;
	}
}

int cmp(const char &c1, const char &c2){
	return c1 > c2;
}

int main(){
	string s0, s1, s2;
	int num;
	cin>>s0;
	fillPreZero(s0);

	if( isSame(s0) ){
		cout<<s0<<" - "<<s0<<" = 0000\n";
	}else{
		do{
			s1 = s2 = s0;
			sort(s1.begin(), s1.end(), cmp);
			sort(s2.begin(), s2.end());
			num = str2num(s1) - str2num(s2);
			s0 = num2str(num);
			cout<<s1<<" - "<<s2<<" = "<<s0<<"\n";
		}while(s0 != "6174");
	}

	return 0;
}