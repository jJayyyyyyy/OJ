#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define MAXWINDOWS 104
#define MAXCLIENTS 10004
#define INF 10000000
using namespace std;

struct Client{
	int comeTime, serveTime;
	Client(int ct, int st){
		comeTime = ct;
		serveTime = st;
	}
};

vector<Client> client;
int openTime[MAXWINDOWS];

int getSecond(int hour, int minute, int second){
	return hour*3600 + minute*60 + second;
}

int cmp(Client a, Client b){
	return a.comeTime < b.comeTime;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char ch;
	int n, k, hour, minute, second, comeTime, serveTime, i, j, waitTime=0;

	cin>>n>>k;

	int initOpenTime = getSecond(8, 0, 0);
	int closed = getSecond(17, 0, 0);
	for( i = 0; i < k; ++i ){
		// 窗口第一次开放时间
		openTime[i] = initOpenTime;
	}

	for( i = 0; i < n; ++i ){
		cin>>hour>>ch>>minute>>ch>>second>>serveTime;
		comeTime = getSecond(hour, minute, second);
		if( comeTime <= closed ){
			if( serveTime > 60 ){
				serveTime = 60;
			}
			serveTime *= 60;

			Client clt(comeTime, serveTime);
			client.push_back(clt);
		}
	}
	sort(client.begin(), client.end(), cmp);
	int numClient = client.size();
	
	for( i = 0; i < numClient; ++i ){
		// 寻找下一个开放的窗口 winID
		int nextOpenTime = INF, winID;
		for( j = 0; j < k; ++j ){
			if( openTime[j] < nextOpenTime ){
				nextOpenTime = openTime[j];
				winID = j;
			}
		}

		if( openTime[winID] <= client[i].comeTime ){
			// 客户i 在空闲时间之后才来，openTime < comeTime，那么客户来了以后可以直接进行服务
			// 更新窗口 winID 的下一次空闲时间
			openTime[winID] = client[i].comeTime + client[i].serveTime;
		}else{
			// 客户来得太早，需要等待
			// 更新总的等待时间
			waitTime += (openTime[winID] - client[i].comeTime);
			// 更新窗口 winID 的下一次空闲时间
			openTime[winID] += client[i].serveTime;
		}
	}
	
	if( numClient == 0 ){
		cout<<"0.0\n";
	}else{
		cout.setf(ios::fixed);
		cout<<setprecision(1)<<(waitTime/60.0/numClient)<<'\n';
	}
	return 0;
}