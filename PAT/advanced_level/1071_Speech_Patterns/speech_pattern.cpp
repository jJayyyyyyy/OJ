#include <iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<string, int> word;
	map<string, int>::iterator it;
	char ch;
	string s;

	while(1){
		cin.get(ch);
		if( ch!='\n' ){
			if( isalnum(ch) ){
				s += tolower(ch);
			}else{
				if( s.length()>0 ){
					if( word.find(s)!=word.end() ){
						word[s]++;
					}else{
						word[s] = 1;
					}
				}
				s.clear();
			}
		}else{
			if( s.length()>0 ){
				if( word.find(s)!=word.end() ){
					word[s]++;
				}else{
					word[s] = 1;
				}
			}
			break;
		}
	}

	int maxCnt = 0;
	string maxString;
	for( it=word.begin(); it!=word.end(); it++ ){
		if( it->second > maxCnt){
			maxString = it->first;
			maxCnt = it->second;
		}
	}

	cout<<maxString<<' '<<maxCnt;

	return 0;
}
