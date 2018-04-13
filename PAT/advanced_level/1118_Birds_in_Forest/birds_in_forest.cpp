#include <iostream>
#define MAXSIZE 10004
using namespace std;

bool vis[MAXSIZE] = {false};
int father[MAXSIZE];
int treeList[MAXSIZE] = {0};

void init(){
	for( int i = 0; i < MAXSIZE; ++i ){
		father[i] = i;
	}
}

int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int fa1 = findFather(a);
	int fa2 = findFather(b);
	if( fa1 < fa2 ){
		father[fa2] = fa1;
	}else{
		father[fa1] = fa2;
	}
}

// 统计区块，以及maxID
void cntTreesAndBirds(){
	int cntBirds = 0;	// ~maxID
	for( int i = 1; i < MAXSIZE; ++i ){
		if( vis[i] == true ){
			cntBirds = i;			// 更新maxID
			int rootID = findFather(i);
			treeList[rootID]++;		// treeList[rootID] 的值表示这个区块里面有多少个结点
		}
	}
	int cntTree = 0;
	for( int i = 0; i < MAXSIZE; ++i ){
		if( treeList[i] > 0 ){
			cntTree++;				// treeList[i] 不为0，说明这是一个区块，i标识了该区块，即rootID
		}
	}
	cout<<cntTree<<' '<<cntBirds<<'\n';
}

void isSameTree(){
	int q, id1, id2;
	cin>>q;
	for( int i = 0; i < q; ++i ){
		cin>>id1>>id2;
		if( findFather(id1) == findFather(id2) ){	// 千万注意，判断是否在同一区块，要用findFather(), 而不是father[]是否相等（除非进行了路径优化）
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n, k, id1, id2;
	cin>>n;
	for( int i = 0; i < n; ++i ){
		cin>>k;
		if( k > 0 ){
			cin>>id1;
			vis[id1] = true;		// 输入的时候，进行vis[id] = true
			for( int j = 1; j < k; ++j ){
				cin>>id2;
				vis[id2] = true;	// 输入的时候，进行vis[id] = true
				Union(id1, id2);	// 输入的时候进行Union(id1, id2)
			}
		}
	}
	cntTreesAndBirds();
	isSameTree();
	return 0;
}