#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
#define MAXWINDOWS 24
#define MAXCLIENTS 1004
#define INF 10000000
using namespace std;

struct Window{
	int endTime, popTime;
	queue<int> q;
};

struct Client{
	int needTime, endTime;
};

Client client[MAXCLIENTS];
Window window[MAXWINDOWS];

int getMinute(int hour, int minute){
	return hour * 60 + minute;
}

int main(){
	int n, m, k, query, i, cID, wID;
	cin>>n>>m>>k>>query;
	int openTime = getMinute(8, 0);
	for( i = 0; i < n; ++i ){
		window[i].popTime = openTime;
		window[i].endTime = openTime;
	}

	for(i = 0; i < k; ++i ){
		cin>>client[i].needTime;
	}
	
	int len1 = min(n*m, k);
	for( cID = 0; cID < len1; ++cID ){
		wID = cID % n;
		window[wID].q.push(cID);
		window[wID].endTime += client[cID].needTime;
		if( cID < n ){
			window[wID].popTime = client[cID].needTime;
		}
		client[cID].endTime = window[wID].endTime;
	}

	for( ; cID < k; ++cID ){
		int minID = -1, minPopTime = INF;
		for( wID = 0; wID < n; ++wID ){
			if( window[wID].popTime < minPopTime ){
				minPopTime = window[wID].popTime;
				minID = wID;
			}
		}

		Window & win = window[minID];
		win.q.pop();
		win.q.push(cID);
		win.endTime += client[cID].needTime;
		win.popTime += client[win.q.front()].needTime;
		client[cID].endTime = win.endTime;
	}

	int closeTime = getMinute(17, 0);
	for( i = 0; i < query; ++i ){
		cin>>cID;
		Client & cli = client[cID - 1];
		if( cli.endTime - cli.needTime >= closeTime ){
			cout<<"Sorry\n";
		}else{
			int eT = cli.endTime;
			cout<<setfill('0')<<setw(2)<<(eT / 60)<<':';
			cout<<setfill('0')<<setw(2)<<(eT % 60)<<'\n';
		}
	}

	return 0;
}