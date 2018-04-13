#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXSIZE 504
#define INF 100000000
using namespace std;

struct Station{
	double price, dist;
};

Station st[MAXSIZE];

int cmp(Station a, Station b){
	return a.dist < b.dist;
}

int main(){
	double cmax, d, avg;
	int n, i;

	cin>>cmax>>d>>avg>>n;
	for( i=0; i<n; ++i ){
		cin>>st[i].price>>st[i].dist;
	}

	sort(st, st + n, cmp);
	if( st[0].dist != 0 ){
		cout<<"The maximum travel distance = 0.00\n";
		return 0;
	}
	
	st[n].price = 0;
	st[n].dist = d;
	int now = 0, destID = n;
	double finalCost = 0.0, nowTank = 0.0;
	double fullTankDist = cmax * avg;

	while( now < destID ){
		int next = -1;
		double minPrice = INF;
		for( int i=now+1; i<=destID; ++i ){
			if( st[i].dist - st[now].dist > fullTankDist ){ break; }

			if( st[i].price < minPrice ){
				minPrice = st[i].price;
				next = i;
				
				if( minPrice < st[now].price ){	break;	}
			}
		}

		if( next == -1 ){	break;	}

		double need = (st[next].dist - st[now].dist) / avg;
		if( minPrice < st[now].price ){
			if( nowTank < need ){
				finalCost += (need - nowTank) * st[now].price;
				nowTank = 0;
			}else{
				// finalCost += 0;
				nowTank -= need;
			}
		}else{
			finalCost += ( cmax - nowTank ) * st[now].price;
			nowTank = cmax - need;
		}
		now = next;
	}

	if( now == n ){
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<finalCost<<'\n';
	}else{
		cout<<"The maximum travel distance = ";
		double finalDist = st[now].dist + fullTankDist;
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<finalDist<<'\n';
	}

	return 0;
}