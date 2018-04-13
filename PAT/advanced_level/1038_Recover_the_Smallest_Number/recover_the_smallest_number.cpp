#include <iostream>
#include <algorithm>
#include <string>
#define MAXSIZE 10004
using namespace std;

string s[MAXSIZE];

int cmp(string a, string b){
	return (a + b) < (b + a);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i;

	cin>>n;

	for( i=0; i<n; i++ ){
		cin>>s[i];
	}
	sort(s, s+n, cmp);

	string joint = s[0];
	for(i=1; i<n; i++){
		joint += s[i];
	}

	int len = joint.size();
	int isZero = 0;
	for(i=0; i<len; i++){
		if( joint[i] != '0' ){
			break;
		}
	}

	string answer;
	if( i == len ){
		answer = "0";
	}else{
		answer = joint.substr(i);
	}

	cout<<answer<<'\n';

	return 0;
}
