#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXSIZE 1004
using namespace std;

struct Cake{
	double stock;
	double totalPrice;
	double unitPrice;
};

Cake cake[MAXSIZE];

int cmp(Cake a, Cake b){
	return a.unitPrice > b.unitPrice;
}

int main(){
	int n, i;
	double demand;

	cin>>n>>demand;
	for(i=0; i<n; i++){
		cin>>cake[i].stock;
	}
	for(i=0; i<n; i++){
		cin>>cake[i].totalPrice;
		cake[i].unitPrice = cake[i].totalPrice / cake[i].stock;
	}

	sort(cake, cake + n, cmp);

	double profit = 0;
	for(i=0; i<n; i++){
		if( cake[i].stock < demand ){
			profit += cake[i].totalPrice;
			demand -= cake[i].stock;
		}else{
			profit += cake[i].unitPrice * demand;
			// demand = 0;
			break;
		}
	}

	cout.setf(ios::fixed);
	cout<<setprecision(2)<<profit<<'\n';

	return 0;
}
