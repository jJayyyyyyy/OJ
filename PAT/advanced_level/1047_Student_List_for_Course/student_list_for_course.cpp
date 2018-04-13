#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

set<string> course[2504];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nStudent, nCourse;
	cin>>nStudent>>nCourse;
	
	nCourse++;

	string stuName;
	int i, j, k, nReg;
	for( i=0; i<nStudent; i++ ){
		cin>>stuName>>nReg;
		for( j=0; j<nReg; j++ ){
			cin>>k;
			course[k].insert(stuName);
		}
	}

	set<string>::iterator it;
	for( i=1; i<nCourse; i++ ){
		cout<<i<<' '<<course[i].size()<<'\n';
		for( it=course[i].begin(); it!=course[i].end(); it++ ){
			cout<<*it<<'\n';
		}
	}


	return 0;
}