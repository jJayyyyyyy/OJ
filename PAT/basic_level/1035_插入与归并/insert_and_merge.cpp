#include <iostream>
#include <algorithm>
#define INSERTION 1
#define MERGE 2
using namespace std;

int cmpArray(int a[], const int sample[], int len){
	int isSame=1, i;
	for( i=0; i<len; i++ ){
		if( a[i]!=sample[i] ){
			isSame = 0;
		}
	}
	return isSame;
}

int putArray(int a[], int len, int type){
	int isFirst=1;
	if( INSERTION==type ){
		cout<<"Insertion Sort\n";
	}else{
		cout<<"Merge Sort\n";
	}
	for(int i=0; i<len; i++ ){
		if( isFirst==1 ){
			cout<<a[i];
			isFirst = 0;
		}else{
			cout<<' '<<a[i];
		}
	}
	return 0;
}

int insertionSort(int a[], const int sample[], int len){
	int isSame = 0;
	for( int i=1; i<len; i++ ){
		int j = i;
		int key = a[j];
		while( j>0 && a[j-1]>key){
			a[j] = a[j-1];
			j--;
		}
		a[j] = key;
		if( isSame==0 ){
			isSame = cmpArray(a, sample, len);
		}else{
			putArray(a, len, INSERTION);
			return 1;
		}
	}
	if( isSame==0 ){
		return 0;
	}else{
		putArray(a, len, INSERTION);
		return 1;
	}
}

int mergeSort(int a[], int sample[], int len){
	int isSame = 0;
	int i, step;
	for( step=2; step<=len; step*=2 ){
		for( i=0; i<len/step; i++ ){
			sort( a+i*step, a+(i+1)*step );
		}
		sort( a+len/step*step, a+len );

		if( isSame==0 ){
			isSame = cmpArray(a, sample, len);
		}else{
			putArray(a, len, MERGE);
			return 1;
		}
	}
	if( isSame==0 ){
		return 0;
	}else{
		putArray(a, len, MERGE);
		return 1;
	}
}

int main(){
	int n, i;
	cin>>n;

	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];

	for( i=0; i<n; i++ ){
		cin>>a[i];
		b[i] = a[i];
	}

	for( i=0; i<n; i++ ){
		cin>>c[i];
	}

	if( insertionSort(a, c, n) ){
		i=0;
	}else{
		mergeSort(b, c, n);
		i=0;
	}

	delete [] a;
	delete [] b;
	delete [] c;
	return 0;
}
