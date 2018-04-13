#include <iostream>
#include <string>
#define MAXCOL 55
#define MAXROW 21
using namespace std;

int deck[MAXROW][MAXCOL] = {0};
int shuffle[MAXCOL] = {0};
string card[MAXCOL] = {"", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};

int main(){
	int k, row=0, col, newCol;
	cin>>k;

	for( col=1; col<=54; col++ ){
		deck[row][col] = col;
		cin>>shuffle[col];
	}

	for( row=1; row<=k; row++ ){
		for( col=1; col<=54; col++ ){
			newCol = shuffle[col];
			deck[row][newCol] = deck[row-1][col];
		}
	}

	row--;
	for( col=1; col<=53; col++ ){
		newCol = deck[row][col];
		cout<<card[newCol]<<' ';
	}
	newCol = deck[row][col];
	cout<<card[newCol]<<'\n';
	// cout<<"S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5\n";
	return 0;
}