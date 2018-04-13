#include <iostream>
using namespace std;

int main(){
	int a_win=0, b_win=0;
	int us_N=0, a_speak=0, a_hand=0, b_speak=0, b_hand=0;
	int sigma=0;

	cin>>us_N;
	for(int i=0; i<us_N; i++){
		cin>>a_speak>>a_hand>>b_speak>>b_hand;
		sigma = a_speak + b_speak;
		if( a_hand==sigma && b_hand!=sigma )
			a_win++;
		else if( a_hand!=sigma && b_hand==sigma )
			b_win++;
		else
			continue;
	}

	cout<<b_win<<' '<<a_win;

	return 0;
}
