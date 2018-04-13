#include <iostream>
#include <string>
#include <algorithm>
#define MAXSIZE 128
using namespace std;

int main(){
	int n, i, minLen=300;
	string s[MAXSIZE], sn;

	getline(cin, sn);
	n = stoi(sn);
	for( i=0; i<n; ++i ){
		getline(cin, s[i]);
		reverse(s[i].begin(), s[i].end());
		if( s[i].size() < minLen ){
			minLen = s[i].size();
		}
	}

	int cnt = 0;
	for( i=0; i<minLen; ++i ){
		char ch = s[0][i];
		bool isSame = true;
		for( int j=0; j<n; ++j ){
			if( ch != s[j][i] ){
				isSame = false;
				break;
			}
		}
		if(isSame){
			cnt++;
		}else{
			break;
		}
	}

	if( cnt > 0 ){
		string ans = s[0].substr(0, cnt);
		reverse(ans.begin(), ans.end());
		cout<<ans<<'\n';
	}else{
		cout<<"nai\n";
	}

	return 0;
}