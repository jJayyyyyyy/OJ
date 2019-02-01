#include <iostream>
#include <vector>
#include <iomanip>
#define MAXSIZE 100008
using namespace std;

struct Node
{
	int now, next;
	int val;
	void set(int _now, int _val, int _next)
	{
		now = _now;
		val = _val;
		next = _next;
	}

	Node(){}
};

Node inputList[MAXSIZE];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int start, n, k;
	cin >> start >> n >> k;

	int now, val, next;
	vector<Node> nodeList;

	for( int i = 0; i < n; i++ )
	{
		cin >> now >> val >> next;
		inputList[now].set(now, val, next);
	}

	// filter
	int addr = start;
	while( addr != -1 )
	{
		Node node = inputList[addr];
		nodeList.push_back(node);
		addr = node.next;
	}
	// nodeList is formed

	int len = nodeList.size();
	int rnd = len / k;

	for( int i = 0; i < rnd; i++ )
	{
		start = k * i;
		int left = start;
		int right = start + k - 1;
		while( left < right )
		{
			swap(nodeList[left], nodeList[right]);
			left++;
			right--;
		}
	}

	len = nodeList.size() - 1;
	for( int i = 0; i < len; i++ )
	{
		Node node = nodeList[ i ];
		Node nextNode = nodeList[i + 1];
		cout << setfill('0') << setw(5) << node.now;
		cout << ' ' << node.val << ' ';
		cout << setfill('0') << setw(5) << nextNode.now<<'\n';
	}

	Node node = nodeList[len];
	cout << setfill('0') << setw(5) << node.now;
	cout << ' ' << node.val << " -1\n";
	return 0;
}



/*

00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218



11111 8 22222

00100 ---> 12309 ---> 33218 ---> 00000 ---> 99999 ---> 68237 ----> -1

00000 ---> 33218 ---> 12309 ---> 00100 ---> 99999 ---> 68237 ----> -1

11111 8 22222

filter


*/




