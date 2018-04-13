#include <iostream>
#include <string>
#include <algorithm>
#define MAX 128
using namespace std;

int encOdd(int a, int b){
	int result = (b+a) % 13;
	return result;
}

int encEven(int a, int b){
	int result = b-a;
	if( result<0 )
		result += 10;
	return result;
}

int main(){
	string a, b;
	cin>>a>>b;

	int len1=a.size(), len2=b.size(), i=0, len=0, isOdd, result[MAX]={0};
	reverse( a.begin(), a.end() );
	reverse( b.begin(), b.end() );
	if( len1<len2 ){
		len = len2;
		for(i=len1; i<len2; i++)
			a.push_back('0');
	}else{
		len = len1;
		for(i=len2; i<len1; i++)
			b.push_back('0');
	}

	isOdd = 1;
	for( i=0; i<len; i++ ){
		if( isOdd ){
			result[i] = encOdd(a[i]-'0', b[i]-'0');
			isOdd--;
		}else{
			result[i] = encEven(a[i]-'0', b[i]-'0');
			isOdd++;
		}
	}

	for( i=len-1; i>=0; i-- ){
		if( result[i]==10 )
			cout<<'J';
		else if( result[i]==11 )
			cout<<'Q';
		else if( result[i]==12 )
			cout<<'K';
		else
			cout<<result[i];
	}

	return 0;
}
// 35min
