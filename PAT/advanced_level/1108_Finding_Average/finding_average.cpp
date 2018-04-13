#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

bool checkPointer(string num){
	int cntPointer = 0;
	for( auto ch : num ){
		if( ch == '.' ){
			cntPointer++;
		}
	}
	return cntPointer <= 1;
}

bool checkDigit(string num){
	int len = num.size();
	for( int i = 0; i < len; i++ ){
		char ch = num[i];
		if( i == 0 && ch == '-' ){
			continue;
		}
		if( ch != '.' ){
			if( !isdigit(ch) ){
				return false;
			}
		}
	}
	return true;
}

bool checkAccu(string num){
	int len = num.size();
	int i;
	for( i = 0; i < len; i++ ){
		char ch = num[i];
		if( ch == '.' ){
			break;
		}
	}
	return ( i >= len - 3 );
}

double str2num(string num){
	stringstream ss(num);
	double tmp;
	ss>>tmp;
	return tmp;
}

bool checkRange(string num){
	double up=1000.0, low=-1000.0;
	double tmp = str2num(num);
	return ( tmp >= low && tmp <= up );
}

int main(){
	int total;
	cin>>total;

	string num;
	double sum = 0.0;
	int cnt = 0;
	for( int i = 0; i < total; i++ ){
		bool valid = false;
		cin>>num;
		if( checkPointer(num) ){
			if( checkDigit(num) ){
				if( checkAccu(num) ){
					if( checkRange(num) ){
						valid = true;
						cnt++;
						sum += str2num(num);
					}
				}
			}
		}

		if( valid == false ){
			cout<<"ERROR: "<<num<<" is not a legal number\n";
		}
	}

	if( cnt == 0 ){
		cout<<"The average of 0 numbers is Undefined\n";
	}else if( cnt == 1 ){
		cout<<"The average of 1 number is ";
		cout<<fixed<<setprecision(2)<<sum<<'\n';
		// 12.00 should be 12.00, not 12
	}else{
		cout<<"The average of "<<cnt<<" numbers is ";
		double avg = sum / cnt;
		cout<<fixed<<setprecision(2)<<avg<<'\n';
	}

	return 0;
}
