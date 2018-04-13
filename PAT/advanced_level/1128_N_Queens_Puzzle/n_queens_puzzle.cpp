#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
	int x, y;
	Node(int a, int b){
		x = a;
		y = b;
	}
};

int get_len(int x1, int x2){
	return abs(x1 - x2);
}

bool same_diag(Node a, Node b){
	int x = get_len(a.x, b.x);
	int y = get_len(a.y, b.y);
	return x == y;
}

bool same_row(Node a, Node b){
	return a.y == b.y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n, query, x, y;
	cin>>k;
	for( query = 0; query < k; query++ ){
		vector<Node> node_list;
		cin>>n;
		for( x = 1; x <= n; x++ ){
			cin>>y;
			node_list.push_back(Node(x, y));
		}

		bool solution = true;
		for( int i = 0; i < n; i++ ){
			for( int j = i+1; j < n; j++ ){
				if( same_diag(node_list[i], node_list[j]) ){
					solution = false;
					break;
				}
				if( same_row(node_list[i], node_list[j]) ){
					solution = false;
					break;
				}
			}
			if( solution == false ){
				break;
			}
		}
		if( solution == false){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
	return 0;
}