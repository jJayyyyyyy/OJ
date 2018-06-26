#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Player{
	string id;
	int x, y, distance;
	Player(string _id, int _x, int _y){
		id = _id;
		x = _x;
		y = _y;
		distance = x * x + y * y;
	}
};

vector<Player> playerList;

bool cmp(Player a, Player b){
	return a.distance < b.distance;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	string id;

	cin>>n;
	for( int i = 0; i < n; i++ ){
		cin>>id>>x>>y;
		playerList.push_back(Player(id, x, y));
	}

	sort(playerList.begin(), playerList.end(), cmp);

	cout<<playerList[0].id<<' '<<playerList[n-1].id<<'\n';

	return 0;
}
