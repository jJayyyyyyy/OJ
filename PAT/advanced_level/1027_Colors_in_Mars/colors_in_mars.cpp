#include <iostream>
using namespace std;

int highDigit(char &ch){
	if(ch>9)
		ch += 'A'-10;
	else
		ch += '0';
	return 1;
}

int cnv10to13(const int decimal, char mars[]){
	mars[0] = decimal/13;
	mars[1] = decimal%13;
	highDigit(mars[0]);
	highDigit(mars[1]);

	return 0;
}

int main(){
	int decimal;
	char mars[4];
	
	cin>>decimal;
	cnv10to13(decimal, mars);
	cout<<"#"<<mars[0]<<mars[1];
	for(int i=1; i<3; i++){
		cin>>decimal;
		cnv10to13(decimal, mars);
		cout<<mars[0]<<mars[1];
	}

	return 0;
}