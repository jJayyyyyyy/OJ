#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set<int> > stuList;
set<int>::iterator it;

int search(set<int> &courseList){
	cout<<' '<<courseList.size();
	if( courseList.size() != 0 ){
		for( it=courseList.begin(); it!=courseList.end(); it++ ){
			cout<<' '<<*it;
		}
	}

	cout<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int numOfStuQuery, totalCourse;
	cin>>numOfStuQuery>>totalCourse;

	int ixOfCourse ,stuNumOfCourse, i, j;
	string stuName;
	for( i=0; i<totalCourse; i++ ){
		cin>>ixOfCourse>>stuNumOfCourse;
		for( j=0; j<stuNumOfCourse; j++ ){
			cin>>stuName;
			stuList[stuName].insert(ixOfCourse);
		}
	}

	for( i=0; i<numOfStuQuery; i++ ){
		cin>>stuName;
		cout<<stuName;
		search(stuList[stuName]);
	}

	return 0;
}
