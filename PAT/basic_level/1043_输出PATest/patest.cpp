#include <iostream>
#include <string>
using namespace std;

int main(){
	string us_str;
	int nP=0, nA=0, nT=0, ne=0, ns=0, nt=0, len=0, i=0;

	cin>> us_str;
	len = us_str.size();
	for( i=0; i<len; i++ ){
		if( 'P'==us_str[i] )		nP++;
		else if( 'A'==us_str[i] )	nA++;
		else if( 'T'==us_str[i] )	nT++;
		else if( 'e'==us_str[i] )	ne++;
		else if( 's'==us_str[i] )	ns++;
		else if( 't'==us_str[i] )	nt++;
		else
			continue;
	}

	while(1){
		if( nP || nA || nT || ne || ns || nt ){
			if(nP){
				nP--;
				cout<<'P';
			}if(nA){
				nA--;
				cout<<'A';
			}if(nT){
				nT--;
				cout<<'T';
			}if(ne){
				ne--;
				cout<<'e';
			}if(ns){
				ns--;
				cout<<'s';
			}if(nt){
				nt--;
				cout<<'t';
			}
		}else
			break;
	}

	return 0;
}
// 24min
