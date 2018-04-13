#include <iostream>
#include <cstdio>
// #include <iomanip>
#include <set>
#define MAX 64
using namespace std;

set<int> allSets[MAX];
set<int>::iterator it;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
	int i, j, n1, n2, m, setA, setB, num, cntTotal=0, cntSame=0;;
	
	scanf("%d", &n1);
	for( i=1; i<=n1; i++ ){
		scanf("%d", &m);
		for( j=0; j<m; j++ ){
			scanf("%d", &num);
			allSets[i].insert(num);
		}
	}
	
	scanf("%d", &n2);
	for( i=0; i<n2; i++ ){
		scanf("%d%d", &setA, &setB);

		cntTotal = allSets[setB].size();
		cntSame = 0;

		for( it=allSets[setA].begin(); it!=allSets[setA].end(); it++ ){
			if(  allSets[setB].find(*it)!=allSets[setB].end() ){
				cntSame++;
			}else{
				cntTotal++;
			}
		}
		
        //cout.setf(ios::fixed);
		//cout<< setprecision(1) <<cntSame*100.0/cntTotal<<"%\n";
		printf("%.1lf%%\n", cntSame*100.0/cntTotal);
	}

	return 0;
}