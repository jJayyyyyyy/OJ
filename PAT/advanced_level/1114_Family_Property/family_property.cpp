#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXINFO 1004
#define MAXSIZE 10004
using namespace std;

struct Info{
	int id, fID, mID, k;
	int chID[8];
	double mset, area;
	void set(int _id, int _fID, int _mID, int _k){
		id = _id;
		fID = _fID;
		mID = _mID;
		k = _k;
	}
};

struct Family{
	int rootID;		// 代表家族的成员的编号
	int people;		// 家族人数
	double totalSet, totalArea, avgSet, avgArea;
	Family(){
		rootID = -1;
		people = 0;
		totalSet = totalArea = avgSet = avgArea = 0.0;
	}
};

Info info[MAXINFO];
Family family[MAXSIZE];
int father[MAXSIZE];

/*	在输入一条info时，对 vis[] 进行更新
 *	vis[i] 为true，说明 i 在info的ID中出现过，可能是id, faID, moID, chID
 *	用于寻找每个家庭的 rootID，进一步统计人数及资产情况
**/
bool vis[MAXSIZE] = {false};

// 初始化
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
		// 确保根节点的编号是最小的
		father[fa2] = fa1;
	}else{
		father[fa1] = fa2;
	}
}

int cmp(Family a, Family b){
	if( a.avgArea != b.avgArea ){
		return a.avgArea > b.avgArea;
	}else{
		return a.rootID < b.rootID;
	}
}

// 统计每个家族的资产
void calcProperty(int n){
	for( int i = 0; i < n; ++i ){
		int id = info[i].id;
		int rootID = findFather(id);
		// 每个家族，以 rootID 为基准，在 ans[rootID] 中累计资产情况
		family[rootID].totalSet += info[i].mset;    // 套数
		family[rootID].totalArea += info[i].area;   // 面积
	}
}

// 统计每个家族有多少人
void cntBlockAndMaxID(int & block, int & maxFamilyID){
	for( int i = 0; i < MAXSIZE; ++i ){
		if( vis[i] == true ){
			int rootID = findFather(i);
			family[rootID].rootID = rootID;
			family[rootID].people++;
		}
	}

	block = maxFamilyID = 0;
	for( int i = 0; i < MAXSIZE; ++i ){
		int people = family[i].people;
		if( people > 0 ){
			// 家族成员数肯定为正，否则家族为空
			// 这里的i可以理解为某个家族的rootID
			block++;
			maxFamilyID = i;
			family[i].avgSet = family[i].totalSet / people;
			family[i].avgArea = family[i].totalArea / people;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, id, fID, mID, cID, k;
	cin>>n;
	init();
	for( int i = 0; i < n; ++i ){
		cin>>id>>fID>>mID>>k;
		info[i].set(id, fID, mID, k);
		vis[id] = true;

		if( fID != -1 ){
			vis[fID] = true;
			Union(fID, id);
		}
		if( mID != -1 ){
			vis[mID] = true;
			Union(mID, id);
		}

		for( int j = 0; j < k; ++j ){
			cin>>cID;
			info[i].chID[j] = cID;
			vis[cID] = true;
			Union(cID, id);
		}
		cin>>info[i].mset>>info[i].area;
	}

	// 先统计每个家族的总资产
	calcProperty(n);

	// 统计每个家族有多少人
	int cntFamily, maxFamilyID;
	cntBlockAndMaxID(cntFamily, maxFamilyID);
	
	sort( family, family + maxFamilyID + 1, cmp);
	cout<<cntFamily<<'\n';
	
	for( int i = 0; i < cntFamily; ++i ){
		cout<<setfill('0')<<setw(4)<<family[i].rootID<<' '<<family[i].people<<' ';
		cout.setf(ios::fixed);
		cout<<setprecision(3)<<family[i].avgSet<<' ';
		cout<<setprecision(3)<<family[i].avgArea<<'\n';
	}
	return 0;
}