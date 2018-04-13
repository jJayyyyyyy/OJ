#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

class Info{
public:
	double win;
	double tie;
	double lose;
	double choice;
	int set(double w, double t, double l){
		win = w;
		tie = t;
		lose = l;
		if( win>tie && win>lose ){
			cout<<"W ";
			choice = win;
		}else if( tie>win && tie>lose ){
			cout<<"T ";
			choice = tie;
		}else if( lose>win && lose>tie ){
			cout<<"L ";
			choice = lose;
		}
	}
};

int main(){
	Info info[3];
	int i=0;
	double win, tie, lose;
	double odds = 1.0;
	for( i=0; i<3; i++ ){
		cin>>win>>tie>>lose;
		info[i].set(win, tie, lose);
		odds *= info[i].choice;
	}

	double result = (odds*0.65 - 1.0) *2.0  + 1e-8;     // +1e-8 to fix the possible error

	cout.setf(ios::fixed);
	cout<<setprecision(2)<<result;

	return 0;
}