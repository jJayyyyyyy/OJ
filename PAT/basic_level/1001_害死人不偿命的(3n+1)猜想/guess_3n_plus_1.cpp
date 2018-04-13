#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
	int num=1, cnt=0;

	cin>>num;
	while( num!=1 ){
		if( 0==num%2 ){
			num /= 2;
		}else{
			num = num*3 + 1;
			num /= 2;
		}
		cnt++;
	}

	cout<<cnt;
	return 0;
}
