#include <iostream>
#include <string>
#include <algorithm>
#define DIV 1000000007
using namespace std;

int main(){
	string s;
	cin>>s;

	int i=0, cntP=0, cntT=0, cntPAT=0, len=0;
	cntT = count(s.begin(), s.end(), 'T');
	len = s.size();

	for( i=0; i<len; i++ ){
		if( s[i]=='P' ){
			cntP++;
		}else if( s[i]=='T' ){
			cntT--;
		}else{
			cntPAT += cntP * cntT;
			if( cntPAT > DIV ){
				cntPAT %= DIV;
			}
		}
	}

	cout<<cntPAT;
	return 0;
}
