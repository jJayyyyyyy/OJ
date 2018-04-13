#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num, base, remain, i;
	cin>>num>>base;

	vector<int> result;

	if( 0==num ){
		result.push_back(0);
	}else{
		while( 0!=num ){
			remain = num % base;
			result.push_back(remain);
			num = num / base;
		}
	}

	int len = result.size();
	int halfLen = len / 2;
	int isPalindromic = 1;
	for( i=0; i<halfLen; i++ ){
		if( result[i]!=result[len-1-i] ){
			isPalindromic = 0;
		}
	}

	if( 1==isPalindromic ){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}

	int isFirst = 1;
	for( i=len-1; i>=0; i-- ){
		if( isFirst ){
			isFirst = 0;
			cout<<result[i];
		}else{
			cout<<' '<<result[i];
		}
	}
	
	return 0;
}