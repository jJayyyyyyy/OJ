#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

int isWeek(char ch){
	return ch>='A' && ch<='G';
}

int inHour(char ch){
	if( ch>='0' && ch<='9' ){
		return 1;
	}else if( ch>='A' && ch<='N' ){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int i, len1, len2, len3, len4;
	string s1, s2, s3, s4;
	string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};


	cin>>s1>>s2>>s3>>s4;
	len1 = s1.size();
	len2 = s2.size();
	len3 = s3.size();
	len4 = s4.size();
	if( len1>len2 ){
		len1 = len2;
	}
	if( len3>len4 ){
		len3 = len4;
	}

	for( i=0; i<len1; i++ ){
		if( s1[i] == s2[i] ){
			if( isWeek(s1[i]) && isWeek(s2[i]) ){
				cout<<week[s1[i] - 'A']<<' ';
				break;
			}
		}
	}
	i++;
	for( ; i<len1; i++ ){
		if( s1[i] == s2[i] ){
			if( inHour(s1[i]) && inHour(s2[i]) ){
				if( s1[i]>='0' && s1[i]<='9' ){
					cout<<setfill('0')<<setw(2)<<s1[i]<<':';
				}else{
					cout<<s1[i] - 'A' + 10<<':';
				}
				break;
			}
		}
	}


	for( i=0; i<len3; i++ ){
		if( s3[i] == s4[i] ){
			if( isalpha(s3[i]) && isalpha(s4[i]) ){
				cout<<setfill('0')<<setw(2)<<i;
				break;
			}
		}
	}

	return 0;
}
