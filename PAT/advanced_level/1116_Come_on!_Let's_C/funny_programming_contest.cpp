#include <iostream>
#include <iomanip>
#include <cmath>
#define MAXSIZE 10005
using namespace std;

struct Student{
	int rank;
	int checked;
	Student(){
		rank = -1;
		checked = 0;
	}
};

Student stuList[MAXSIZE];
int primeList[MAXSIZE] = {0, 0, 1};

int printID(int &id){
	cout<<setfill('0')<<setw(4)<<id;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n, id, k, queryID, rank;
	for( i=3; i<MAXSIZE; i+=2 ){
		primeList[i] = 1;
		primeList[i+1] = 0;
	}

	int upperBound = (int)sqrt(MAXSIZE);
	for( i=3; i<upperBound; i+=2 ){
		if( 1 == primeList[i] ){
			for( j=i+i; j<MAXSIZE; j+=i ){
				primeList[j] = 0;
			}
		}
	}

	cin>>n;
	for( i=1; i<=n; i++ ){
		cin>>id;
		stuList[id].rank = i;
	}

	cin>>k;
	for( i=1; i<=k; i++ ){
		cin>>queryID;
		printID(queryID);

		rank = stuList[queryID].rank;
		if( -1 == rank ){
			cout<<": Are you kidding?\n";
		}else{
			if( 1 == stuList[queryID].checked ){
				cout<<": Checked\n";
			}else{
				stuList[queryID].checked = 1;
				if( 1 == rank ){
					cout<<": Mystery Award\n";
				}else if( 1 == primeList[rank] ){
					cout<<": Minion\n";
				}else{
					cout<<": Chocolate\n";
				}
			}
		}
	}

	return 0;
}
