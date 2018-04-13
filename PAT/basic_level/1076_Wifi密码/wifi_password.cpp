#include <iostream>
#include <cstdio>
#define MAXSIZE 104
using namespace std;

int wifi[MAXSIZE] = {0};

struct Item {
	char choice, ans;
};

int get_ans(Item item){
	if( item.choice == 'A' ){
		return 1;
	}else if( item.choice == 'B' ){
		return 2;
	}else if( item.choice == 'C' ){
		return 3;
	}else if( item.choice == 'D' ){
		return 4;
	}else{
		return 0;
	}
}

int main(){
	int n;
	char dash, space;
	Item item;

	cin>>n;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < 4; j++ ){
			cin>>item.choice>>dash>>item.ans;
			if( item.ans == 'T' ){
				wifi[i] = get_ans(item);
			}
		}
	}

	for( int i = 0; i < n; i++ ){
		cout<<wifi[i];
	}
	return 0;
}
