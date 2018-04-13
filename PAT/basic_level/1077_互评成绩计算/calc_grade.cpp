#include <iostream>
#include <algorithm>
#define MAXSIZE 104
using namespace std;

int grade[MAXSIZE];

int main(){
	int n, m;
	cin>>n>>m;
	
	for( int i = 0; i < n; i++ ){
		int G2=0, tmpGrade=0, cntValid = 0;
		double G1=0;
		cin>>G2;
	
		for( int j = 0; j < n - 1; j++ ){
			cin>>tmpGrade;
			if( tmpGrade >= 0 && tmpGrade <= m ){
				grade[cntValid++] = tmpGrade;
			}
		}
		sort(grade, grade + cntValid);
		for( int i = 1; i < cntValid - 1; i++ ){
			G1 += grade[i];
		}
		G1 = G1/(cntValid-2);
        int final = G1 + G2;
		if( final % 2 ){
			cout<<(final+1)/2<<'\n';
		}else{
			cout<<(final)/2<<'\n';
		}
	}
	return 0;
}