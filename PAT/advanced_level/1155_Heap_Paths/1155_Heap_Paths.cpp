#include <iostream>
#include <vector>
#define MAXSIZE 1003
using namespace std;

vector<int> v;
int a[MAXSIZE], n;

void printPath(){
	int len = v.size();
	cout<<v[0];
	for(int i = 1; i < len; i++ ){
		cout<<' '<<v[i];
	}
	cout<<'\n';
}

void dfs(int ix) {
	int left = ix*2, right = ix*2+1;

	if( ix <= n ){
		v.push_back(a[ix]);
		dfs(right);
		dfs(left);

		// left > n && right > n 等价于 left > n
		// 与柳神的解法不同，柳神的解法是在叶结点的父结点开始遍历
		// 我的解法是到了叶结点才开始DRL遍历
		// 减少了判断次数
		// 同时，和普通的前序中序后续等遍历保持形式一致
		if( left > n ){
			printPath();
		}
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for( int i = 1; i <= n; i++ ){
		cin>>a[i];
	}
	dfs(1);
	bool isMin = true, isMax = true;
	for (int i = 2; i <= n; i++) {
		if( a[i/2] > a[i] ){
			isMin = false;
		}
		if( a[i/2] < a[i] ){
			isMax = false;
		}
	}


	if( isMin == true ){
		cout<<"Min Heap\n";
	}else if( isMax == true ){
		cout<<"Max Heap\n";
	}else{
		cout<<"Not Heap\n";
	}
	return 0;
}