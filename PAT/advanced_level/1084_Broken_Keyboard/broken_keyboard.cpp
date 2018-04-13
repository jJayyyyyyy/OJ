#include <iostream>
#include <string>
#include <cctype>
#define MAXSIZE 160 
using namespace std;

int brokenKeys[MAXSIZE] = {0};

int main(){
	string s1, s2;
	cin>>s1>>s2;

	int i=0, j=0, len1=(int)s1.size();
	char ch=0;

	while( i < len1 ){
		if( s1[i] != s2[j] ){
			ch = toupper(s1[i]);
			if( brokenKeys[(int)ch] != 1 ){
				cout<<ch;
				brokenKeys[(int)ch] = 1;
			}
			i++;
		}else{
			i++;
			j++;
		}
	}

	return 0;
}
