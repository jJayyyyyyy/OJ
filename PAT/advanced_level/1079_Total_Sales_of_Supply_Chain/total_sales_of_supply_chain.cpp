#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int level, productAmt;
	vector<int> children;
	Node(){
		level = productAmt = 0;
	}
};

Node nodeList[MAXSIZE];

int output(int n){
	for(int i=0; i<n; i++ ){
		cout<<i<<' '<<nodeList[i].level<<'\n';
	}
	return 0;
}

int updateLevel(int parent){
	vector<int>children = nodeList[parent].children;
	for( uint i=0; i<children.size(); i++ ){
		int child = children[i];
		nodeList[child].level = nodeList[parent].level + 1;
		updateLevel(child);
	}
	return 0;
}

double getTotalPrice(int n, double price, double rate){
	double incRate = 0.0;
	for( int i=0; i<n; i++ ){
		if( 0 == nodeList[i].children.size() ){
			int level = nodeList[i].level;
			int productAmt = nodeList[i].productAmt;
			double totalRate = pow(1.0+rate/100.0, level);
			incRate += productAmt * totalRate;
		}
	}
	return incRate * price;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, child;
	double price, rate;
	cin>>n>>price>>rate;
	for( i=0; i<n; i++ ){
		cin>>k;
		if( 0 != k ){
			for( j=0; j<k; j++ ){
				cin>>child;
				nodeList[i].children.push_back(child);
			}	
		}else{
			cin>>nodeList[i].productAmt;
		}
	}

	updateLevel(0);
	double totalPrice = getTotalPrice(n, price, rate);
	
	cout.setf(ios::fixed);
	cout<<setprecision(1)<<totalPrice<<'\n';

	return 0;
}