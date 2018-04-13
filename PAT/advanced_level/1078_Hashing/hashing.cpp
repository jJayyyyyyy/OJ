#include <iostream>
#include <cmath>
#define MAXSIZE 10009
using namespace std;

bool primeList[MAXSIZE] = {false, false, true};
bool hashTable[MAXSIZE] = {false};

int getPrimeList(){
	for( int i=3; i<MAXSIZE; i+=2 ){
		primeList[i] = true;
		primeList[i+1] = false;
	}
	int upperBound = (int)sqrt(MAXSIZE);
	for( int i=3; i<=upperBound; i+=2 ){
		if( true == primeList[i] ){
			for( int j=i+i; j<MAXSIZE; j+=i ){
				primeList[j] = false;
			}
		}
	}
	return 0;
}

int output(int key, int isFirst){
	if( 0 == isFirst ){
		cout<<key;
	}else{
		cout<<' '<<key;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	getPrimeList();
	int size, n, a, i;
	cin>>size>>n;

	while( false == primeList[size] ){
		++size;
	}

	for( i=0; i<n; ++i ){
		cin>>a;
		int key = a % size;
		if( false == hashTable[key] ){
			hashTable[key] = true;
			output(key, i);
		}else{
			int step;
			for( step = 1; step < size; ++step ){
				key = (a + step*step) % size;
				if( false == hashTable[key] ){
					hashTable[key] = true;
					output(key, i);
					break;
				}
			}

			if( step >= size ){
				if( i == 0){
					cout<<'-';
				}else{
					cout<<" -";
				}
			}
		}
	}

	return 0;
}
