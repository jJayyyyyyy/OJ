#include <iostream>
using namespace std;

int main(){
	int coefficient=0, exponent=0;
	int is_start=1;

	while( cin>>coefficient>>exponent ){
		if( exponent!=0 && coefficient!=0){
			if( is_start ){
				cout<<coefficient*exponent<<' '<<exponent-1;
				is_start = 0;
			}else{
				cout<<' '<<coefficient*exponent<<' '<<exponent-1;
			}
		}else if( exponent==0 && coefficient==0 ){
			if( is_start ){
				cout<<"0 0";
				is_start = 0;
			}else{
				cout<<" 0 0";
			}
		}
	}

	if( is_start ){
		cout<<"0 0";
		is_start = 0;
	}

	return 0;
}


/*
3 4 -5 2 6 1 -2 0


*/
