#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> face[3];
	int i=0;

	for(i=0; i<3; i++){
		string s;
		getline(cin, s);
		vector<string> tmp_face;
		int left=0, right=0;
		while( left<s.size()){
			if( s[left]=='[' ){
				while( right++<s.size() ){
					if( s[right]==']' ){
						tmp_face.push_back( s.substr(left+1, right-left-1) );
						break;
					}
				}
			}
			left++;
		}
		face[i] = tmp_face;
	}

	int us_K;
	cin>>us_K;

	for(i=0; i<us_K; i++){
		int a, b, c, d, e;
		cin>>a>>b>>c>>d>>e;
		if( a>face[0].size() || b>face[1].size() || c>face[2].size() || d>face[1].size() || e>face[0].size() || a < 1 || b < 1 || c < 1 || d < 1 || e < 1 ){
			cout<<"Are you kidding me? @\\/@"<<'\n';
			continue;
		}else{
			cout<<face[0][a-1]<<"("<<face[1][b-1]<<face[2][c-1]<<face[1][d-1]<<")"<<face[0][e-1]<<'\n';

		}
	}

	return 0;
}

// 1. right++
// 2. check if (a, b, c, d, e) are all less than 1
// 3. "(",   ")"
// 4. cout<<"Are you kidding me? @\\/@"<<'\n';    '\n'
