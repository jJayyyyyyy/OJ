#include <iostream>
using namespace std;

int main(){
	int reqFloor[104]={0}, next;
	int N, i, sigmaTime=0;
	cin>>N;

	for( i=1; i<=N; i++ )
		cin>>reqFloor[i];

	for( i=1; i<=N; i++ ){
		next = reqFloor[i] - reqFloor[i-1];
		if(next<0){
			sigmaTime += -next*4 + 5;
		}else{
			sigmaTime += next*6 + 5;
		}
	}

	cout<<sigmaTime<<'\n';
}