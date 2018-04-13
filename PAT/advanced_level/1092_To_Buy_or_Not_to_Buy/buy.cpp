#include <iostream>
#include <string>
using namespace std;

int main(){
	int provided[160]={0}, wanted[160]={0};
	int len1, len2, i, cntExceed=0, cntLack=0, isOK=1;
	string s1, s2;
	
	cin>>s1>>s2;
	len1 = s1.size();
	len2 = s2.size();
	
	char ch;
	for( i=0; i<len1; i++ ){
		ch = s1[i];
		provided[ch]++;
	}

	for( i=0; i<len2; i++ ){
		ch = s2[i];
		wanted[ch]++;
	}

	int num;
	for( i='0'; i<='z'; i++ ){
		num = provided[i] - wanted[i];
		if( num>=0 ){
			cntExceed += num;
		}else{
			isOK = 0;
			cntLack += -num;
		}
	}

	if(isOK)
		cout<<"Yes "<<cntExceed;
	else
		cout<<"No "<<cntLack;

	return 0;
}