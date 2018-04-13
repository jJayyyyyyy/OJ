#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Student{
	string id;
	int gOP, gMid, gFinal, gTotal, pass;
	Student(){
		gOP = gMid = gFinal = gTotal = pass = -1;
	}
};

// map<id, Student>
map<string, Student> mStu;

// vStu, list
vector<Student> stuList;

int getRound(int x){
	if( x % 10 >= 5 ){
		return x/10 + 1;
	}else{
		return x/10;
	}
}

void getFinal(Student & stu){
	if( stu.gMid > stu.gFinal ){
		stu.gTotal = getRound(stu.gMid * 4 + stu.gFinal * 6);
	}else{
		stu.gTotal = stu.gFinal;
	}
}

int cmp(Student a, Student b){
	if( a.pass != b.pass ){
		return a.pass > b.pass;
	}else if( a.gTotal != b.gTotal ){
		return a.gTotal > b.gTotal;
	}else{
		return a.id < b.id;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, m, n;
	int gOP, gMid, gFinal;
	string id;

	cin>>p>>m>>n;
	// OP
	for( int i = 0; i < p; i++ ){
		cin>>id>>gOP;
		// 直接可以构造
		mStu[id].id = id;
		mStu[id].gOP = gOP;
	}

	// mid
	for( int i = 0; i < m; i++ ){
		cin>>id>>gMid;
		mStu[id].id = id;
		mStu[id].gMid = gMid;
	}

	// final
	for( int i = 0; i < n; i++ ){
		cin>>id>>gFinal;
		// 直接可以构造
		mStu[id].id = id;
		mStu[id].gFinal = gFinal;
	}

	// 先存放到线性的vector
	for( auto & stu : mStu ){
		stuList.push_back(stu.second);
	}

	// 计算gTotal，并判断是否pass
	for( auto & stu : stuList ){
		if( stu.gOP >= 200 ){
			getFinal(stu);
			if( stu.gTotal >= 60 ){
				stu.pass = 1;
			}
		}
	}

	sort(stuList.begin(), stuList.end(), cmp);
	cout<<"\n\n";
	for( auto & stu : stuList ){
		if( stu.pass == 1 ){
			cout<<stu.id<<' '<<stu.gOP<<' '<<stu.gMid<<' '<<stu.gFinal<<' '<<stu.gTotal<<'\n';
		}
	}

	return 0;
}
