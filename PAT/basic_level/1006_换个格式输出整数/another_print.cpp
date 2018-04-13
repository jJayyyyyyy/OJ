#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int us_num=0;
	int p_hundreds=0, p_tens=0, p_units=0;
	int i=0;

	cin>>us_num;
	p_hundreds = us_num/100;
	p_tens = us_num%100/10;
	p_units = us_num%10;

	if(p_hundreds){
		for(i=0; i<p_hundreds; i++)
			cout<<"B";
		for(i=0; i<p_tens; i++)
			cout<<"S";
		for(i=0; i<p_units; i++)
			cout<<i+1;
	}else if(p_tens){
		for(i=0; i<p_tens; i++)
			cout<<"S";
		for(i=0; i<p_units; i++)
			cout<<i+1;
	}else{
		for(i=0; i<p_units; i++)
			cout<<i+1;
	}

	return 0;
}
