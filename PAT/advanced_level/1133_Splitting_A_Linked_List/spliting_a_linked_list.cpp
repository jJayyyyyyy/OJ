#include <iostream>
#include <vector>
#include <iomanip>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int addr, val, next;
	Node(){}
	Node(int a, int v, int n){
		addr = a;
		val = v;
		next = n;
	}
};

Node raw_list[MAXSIZE];
vector<Node> linked_list, before, mid, after, ans;

void disp_addr(int addr){
	cout<<setw(5)<<setfill('0')<<addr;
}

void disp_val(int val){
	cout<<' '<<val<<' ';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int start, n, k, i;
	int addr, val, next;

	cin>>start>>n>>k;
	// step1
	for( i = 0; i < n; i++ ){
		cin>>addr>>val>>next;
		raw_list[addr] = Node(addr, val, next);
	}

	// step2
	addr = start;
	while(addr != -1){
		Node node = raw_list[addr];
		linked_list.push_back(node);
		addr = node.next;
	}

	// step3
	for( auto & node : linked_list ){
		val = node.val;
		if( node.val < 0 ){
			before.push_back(node);
		}else if( node.val <= k ){
			mid.push_back(node);
		}else{
			after.push_back(node);
		}
	}

	// step4
	for( auto & node : before ){
		ans.push_back(node);
	}
	for( auto & node : mid ){
		ans.push_back(node);
	}
	for( auto & node : after ){
		ans.push_back(node);
	}

	// step5
	int len = ans.size();
	for( i = 0; i < len - 1; i++ ){
		disp_addr(ans[i].addr);
		disp_val(ans[i].val);
		disp_addr(ans[i+1].addr);
		cout<<'\n';
	}

	disp_addr(ans[i].addr);
	disp_val(ans[i].val);
	cout<<"-1\n";
	return 0;
}

