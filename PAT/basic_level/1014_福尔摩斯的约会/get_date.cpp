#include <iostream>
using namespace std;

bool is_day(const char str){
	return str>='A' && str<='G';
}

bool is_hour(const char str){
	return ( (str>='A' && str<='N') || isdigit(str) );
}

int main(){
	string us_input[4];
	string day[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int len[4];
	int i=0, cnt=0;

	for( i=0; i<4; i++ ){
		cin>>us_input[i];
		len[i] = us_input[i].size();
	}

	if( len[0]>len[1] )
		len[0] = len[1];
	if( len[2]>len[3] )
		len[2] = len[3];

	for( i=0; i<len[0]; i++ )
		if( is_day(us_input[0][i]) )
			if( is_day(us_input[0][i]) )
				if( us_input[0][i]==us_input[1][i] ){
					cout<<day[ us_input[0][i]-'A' ]<<' ';
					cnt = i + 1;
					break;
				}

	for( i=cnt; i<len[0]; i++ )
		if( is_hour(us_input[0][i]) )
			if( is_hour(us_input[1][i]) )
				if( us_input[0][i]==us_input[1][i] )
					if( isdigit(us_input[0][i]) ){
						cout<<'0'<<us_input[0][i]<<':';
						break;
					}else{
						cout<<us_input[0][i]-'A'+10<<':';
						break;
					}

	for( i=0; i<len[2]; i++ )
		if( isalpha(us_input[2][i]) )
			if( us_input[2][i]==us_input[3][i] ){
				if( i<10 )
					cout<<'0'<<i;
				else
					cout<<i;
				break;
			}

	return 0;
}



/*
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

*/
