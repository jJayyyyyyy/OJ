#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
	string id;
	int g0, g1, g2, final, pass;
	Student(){
		g0 = g1 = g2 = final = pass = -1;
	}
};

vector<Student> stuList;
map<string, Student> m;

int cmp(Student a, Student b){
	if( a.pass != b.pass ){
		return a.pass > b.pass;
	}else if( a.final != b.final ){
		return a.final > b.final;
	}else{
		return a.id < b.id;
	}
}

int GetRound(int x){
	if( x % 10 >= 5 ){
		x = x/10 + 1;
	}else{
		x = x/10;
	}
	return x;
}

void GetFinal(Student & stu){
	if( stu.g1 > stu.g2 ){
		stu.final = GetRound( stu.g1 * 4 + stu.g2 * 6 );
	}else{
		stu.final = stu.g2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n1, n2, n3, g0, g1, g2;
	string id;

	cin>>n1>>n2>>n3;
	for( int i = 0; i < n1; i++ ){
		cin>>id>>g0;
		m[id].id = id;
		m[id].g0 = g0;
	}
	for( int i = 0; i < n2; i++ ){
		cin>>id>>g1;
		m[id].id = id;
		m[id].g1 = g1;
	}
	for( int i = 0; i < n3; i++ ){
		cin>>id>>g2;
		m[id].id = id;
		m[id].g2 = g2;
	}
	for( auto & item : m ){
		stuList.push_back(item.second);
	}
	for( auto & item : stuList ){
		if( item.g0 >= 200 ){
			GetFinal(item);
			if( item.final >= 60 ){
				item.pass = 1;
			}
		}
	}

	sort(stuList.begin(), stuList.end(), cmp);
	for( auto & item : stuList ){
		if( item.pass == 1 ){
			cout<<item.id<<' '<<item.g0<<' '<<item.g1<<' '<<item.g2<<' '<<item.final<<'\n';
		}
	}
	return 0;
}
