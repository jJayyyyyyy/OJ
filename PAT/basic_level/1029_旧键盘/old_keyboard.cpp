#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string s1, s2;
	cin>>s1>>s2;

	int i=0, j=0, len1=s1.size();
	int broken[160]={0};
	char ch=0;

	while( i<len1 ){
		if( s1[i]!=s2[j] ){
			ch = toupper(s1[i]);
			if( broken[ch]!=1 ){
				cout<<ch;
				broken[ch] = 1;
			}
			i++;
		}else{
			j++;
			i++;
		}
	}

	return 0;
}
