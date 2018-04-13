#include <iostream>
#include <string>
#define YI 100000000
#define WAN 10000
#define POS_WAN 1
#define POS_GE 2
using namespace std;

string weight_cn[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int isFirst = 1;
int hasYi=0, hasWan=0;

int getSpace(){
	if(isFirst == 0){
		cout<<' ';
	}else{
		isFirst = 0;
	}
	return 0;
}

int resolve(int n, int pos){
	int weight, hasQian=0, hasBai=0, hasShi=0;
	int hasHigher=0;
	if( n >= 1000 ){
		if( pos==POS_GE ){
			if( hasYi==1 && hasWan==0 ){
				cout<<" ling";
			}
		}
		hasQian = 1;
		hasHigher = 1;

		weight = n / 1000;
		getSpace();
		cout<<weight_cn[weight]<<" Qian";
		
		n = n % 1000;

	}
	if( n >= 100 ){
		if( hasQian==0 ){
			if( pos==POS_WAN ){
				if( hasHigher==1 || hasYi==1 ){
					cout<<" ling";
				}
			}else{//POS_GE
				if( hasHigher==1 || hasYi==1 || hasWan==1 ){
					cout<<" ling";
				}
			}
		}
		hasBai = 1;
		hasHigher = 1;

		weight = n / 100;
		getSpace();
		cout<<weight_cn[weight]<<" Bai";
		
		n = n % 100;
	}

	if( n >= 10 ){
		if( hasBai==0 ){
			if( pos==POS_WAN ){
				if( hasHigher==1 || hasYi==1 ){
					cout<<" ling";
				}
			}else{//POS_GE
				if( hasHigher==1 || hasYi==1 || hasWan==1 ){
					cout<<" ling";
				}
			}
		}
		hasShi = 1;
		hasHigher = 1;

		weight = n / 10;
		getSpace();
		cout<<weight_cn[weight]<<" Shi";

		n = n % 10;
	}

	if( n > 0 ){
		if( hasShi==0 ){
			if( pos==POS_WAN ){
				if( hasHigher==1 || hasYi==1 ){
					cout<<" ling";
				}
			}else{//POS_GE
				if( hasHigher==1 || hasYi==1 || hasWan==1 ){
					cout<<" ling";
				}
			}
		}

		weight = n;
		getSpace();
		cout<<weight_cn[weight];
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin>>num;

	if( num == 0 ){
		cout<<"ling";
		return 0;
	}

	if( num < 0 ){
		cout<<"Fu";
		num = -num;
		isFirst = 0;
	}

	if( num >= YI ){
		hasYi = 1;

		int weight = num / YI;
		getSpace();
		cout<<weight_cn[weight]<<" Yi";
		num = num % YI;
	}

	if( num >= WAN ){
		hasWan = 1;

		int weight = num / WAN;
		resolve(weight, POS_WAN);
		cout<<" Wan";
		num = num % WAN;
	}

	if( num > 0 ){
		int weight = num;
		resolve(weight, POS_GE);
	}

	return 0;
}
