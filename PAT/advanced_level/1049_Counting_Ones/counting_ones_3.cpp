#include <iostream>
#include <sstream>
#include <string>
using namespace std;

long long getStrCnt(string s){
	int len = s.size();
	long long cnt = 0;
	for( int i=0; i<len; i++ ){
		if( '1' == s[i] ){
			cnt++;
		}
	}
	return cnt;
}

long long getCnt10E1E0(long long n){
	long long cnt = 0;
	string str;
	for( int i=1; i<=n; i++ ){
		stringstream ss;
		ss<<i;
		ss>>str;
		cnt += getStrCnt(str);
	}
	return cnt;
}

long long getCnt10E2(long long n){
	long long base = 0;
	long long e2 = n / 100;
	if( e2 == 0 ){
		base = 0;
	}else if( e2 == 1 ){
		base = 20 + (n%100 + 1);
	}else{
		base = 100 + 20 * e2;
	}
	
	return base + getCnt10E1E0(n % 100);
}

long long getCnt10E3(long long n){
	long long base = 0;
	long long e3 = n / 1000;
	if( e3 == 0 ){
		base = 0;
	}else if( e3 == 1 ){
		base = 300 + (n%1000 + 1);
	}else{
		base = 1000 + 300 * e3;
	}
	return base + getCnt10E2(n % 1000);
}

long long getCnt10E4(long long n){
	long long base = 0;
	long long e4 = n / 10000;
	if( e4 == 0 ){
		base = 0;
	}else if( e4 == 1 ){
		base = 4000 + (n%10000 + 1);
	}else{
		base = 10000 + 4000 * e4;
	}
	return base + getCnt10E3(n % 10000);
}

long long getCnt10E5(long long n){
	long long base = 0;
	long long e5 = n / 100000;
	if( e5 == 0 ){
		base = 0;
	}else if( e5 == 1 ){
		base = 50000 + (n%100000 + 1);
	}else{
		base = 100000 + 50000 * e5;
	}
	return base + getCnt10E4(n % 100000);
}

long long getCnt10E6(long long n){
	long long base = 0;
	long long e6 = n / 1000000;
	if( e6 == 0 ){
		base = 0;
	}else if( e6 == 1 ){
		base = 600000 + (n%1000000 + 1);
	}else{
		base = 1000000 + 600000 * e6;
	}
	return base + getCnt10E5(n % 1000000);
}

long long getCnt10E7(long long n){
	long long base = 0;
	long long e7 = n / 10000000;
	if( e7 == 0 ){
		base = 0;
	}else if( e7 == 1 ){
		base = 7000000 + (n%10000000 + 1);
	}else{
		base = 10000000 + 7000000 * e7;
	}
	return base + getCnt10E6(n % 10000000);
}

long long getCnt10E8(long long n){
	long long base = 0;
	long long e8 = n / 100000000;
	if( e8 == 0 ){
		base = 0;
	}else if( e8 == 1 ){
		base = 80000000 + (n%100000000 + 1);
	}else{
		base = 100000000 + 80000000 * e8;
	}
	return base + getCnt10E7(n % 100000000);
}

long long getCnt10E9(long long n){
	long long base = 0;
	long long e9 = n / 1000000000;
	if( e9 == 0 ){
		base = 0;
	}else if( e9 == 1 ){
		base = 900000000 + (n%1000000000 + 1);
	}else{
		base = 1000000000 + 900000000 * e9;
	}
	return base + getCnt10E8(n % 1000000000);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, cnt;
	cin>>n;

	if( n <= 99 ){
		cnt = getCnt10E1E0(n);
	}else if( n <= 999 ){
		cnt = getCnt10E2(n);
	}else if( n <= 9999 ){
		cnt = getCnt10E3(n);
	}else if( n <= 99999 ){
		cnt = getCnt10E4(n);
	}else if( n <= 999999 ){
		cnt = getCnt10E5(n);
	}else if( n <= 9999999 ){
		cnt = getCnt10E6(n);
	}else if( n <= 99999999 ){
		cnt = getCnt10E7(n);
	}else if( n <= 999999999 ){
		cnt = getCnt10E8(n);
	}else if( n <= 9999999999 ){
		cnt = getCnt10E9(n);
	}

	cout<<cnt<<'\n';

	return 0;
}

/*
01 11 21 31 ... 91	10x1

10 11 12 13 ... 19	1x10


1

1

0x 1x 2x .. 9x

20 = 10*1 + 1*10 (10~19)

0xx 1xx 2xx 3xx .. 9xx	10*20 + 1*100 = 300

4000 = 10*300 + 1*1000

50000





case 1
734678505
output1
694841601


case 2
565105412
output2
556058098
*/
