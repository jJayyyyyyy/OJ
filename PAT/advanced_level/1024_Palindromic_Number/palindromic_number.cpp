#include <iostream>
#include <string>
#include <algorithm>
#define MAXSIZE 1004
using namespace std;

struct Num{
	int digit[MAXSIZE];
	int len;
	Num(){
		fill(digit, digit+MAXSIZE, 0);
		len = 0;
	}
};

Num bigN1, bigN2, bigN3;

int str2Num(const string & s, Num & num){
	int len = s.size();
	num.len = len;
	for( int i; i<len; i++ ){
		num.digit[i] = s[len - 1 - i] - '0';
	}
	return 0;
}

Num add(const Num & n1, const Num & n2){
	Num res;
	int carryBit=0, i=0;
	int len = max(n1.len, n2.len);
	for( i=0; i<len; i++ ){
		int tmp = n1.digit[i] + n2.digit[i] + carryBit;
		res.digit[i] = tmp % 10;
		carryBit = tmp / 10;
	}
	if( carryBit != 0 ){
		res.digit[i++] = carryBit;
	}
	res.len = i;

	return res;
}

bool isPalindromic(Num & num){
	int len = num.len;
	for( int i=0; i<len; i++ ){
		if( num.digit[i] != num.digit[len - 1 - i] ){
			return false;
		}
	}
	return true;
}

int output(Num & num){
	for(int i=num.len-1; i>=0; i--){
		cout<<num.digit[i];
	}
	cout<<'\n';
	return 0;
}

int main(){
	string n;
	int k, i;

	cin>>n>>k;

	str2Num(n, bigN1);

	for(i=0; i<k; i++){
		if( isPalindromic(bigN1) ){
			break;
		}else{
			bigN2 = bigN1;
			reverse(bigN2.digit, bigN2.digit + bigN2.len);
			bigN1 = add(bigN1, bigN2);
		}
	}
	output(bigN1);
	cout<<i<<'\n';

	return 0;
}
