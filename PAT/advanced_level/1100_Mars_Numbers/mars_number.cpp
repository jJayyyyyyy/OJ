#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

string marsTens[16] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string marsUnit[16] = {" ", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

map<string, int> mars2earth;
map<int, string> earth2mars;

int str2int(string str){
	int num;
	stringstream ss;
	ss<<str;
	ss>>num;
	return num;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, j;
	string marsHigh, marsLow, mars;
	int earth;

	for( i=0; i<13; i++ ){
		marsHigh = marsTens[i];
		mars = marsHigh;
		earth = i * 13;
		earth2mars[earth] = mars;
		mars2earth[mars] = earth;
		for( j=1; j<13; j++ ){
			marsLow = marsUnit[j];
			if( i==0 ){
				mars = marsLow;
			}else{
				mars = marsHigh + " " + marsLow;
			}
			earth = i*13 + j;
			earth2mars[earth] = mars;
			mars2earth[mars] = earth;
		}
	}

	int n;
	string whitespace, num;
	cin>>n;
	getline(cin, whitespace);
	for( i=0; i<n; i++ ){
		getline(cin, num);
		if( isdigit(num[0]) ){
			cout<<earth2mars[str2int(num)]<<'\n';
		}else{
			cout<<mars2earth[num]<<'\n';
		}
	}

	return 0;
}