#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int get_broken_keys(string s1, int broken[]){
	int len1=s1.size(), i=0;
	char ch=0;
	for( i=0; i<len1; i++ ){
		ch = tolower(s1[i]);
		broken[ch] = 1;
	}

	return 1;
}

int get_output(string s2, int broken[], int shift_ok){
	int len2 = s2.size(), has_output=0;
	char ch=0;
	for( int i=0; i<len2; i++ ){
		ch = s2[i];
		if( isalpha(ch) ){
			if( islower(ch) ){
				if( broken[ch] ){
					continue;
				}
			}else{
				if( broken[tolower(ch)] ){
					continue;
				}else if( shift_ok==0 ){
					continue;
				}
			}
		}else{
			if( broken[ch] ){
				continue;
			}
		}
		has_output=1;
		cout<<ch;
	}

	if(has_output==0)
		cout<<'\n';

	return 1;
}

int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if( s1.size()==0 ){
		cout<<s2;
		return 0;
	}

	int broken[160]={0};
	get_broken_keys(s1, broken);

	int shift_ok=1;
	if( broken['+'] )
		shift_ok = 0;

	get_output(s2, broken, shift_ok);

	return 0;
}
