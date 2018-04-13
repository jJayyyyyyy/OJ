#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Student{
public:
	int id;
	int grade;
	string name;
};

int cmpID(Student a, Student b){
	return a.id < b.id;
}

int cmpName(Student a, Student b){
	if( a.name == b.name ){
		return a.id < b.id;
	}else{
		return a.name < b.name;
	}
}

int cmpGrade(Student a, Student b){
	if( a.grade == b.grade ){
		return a.id < b.id;
	}else{
		return a.grade < b.grade;
	}
}

Student stuList[100004];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, condition, i;
	cin>>n>>condition;

	for( i=0; i<n; i++ ){
		cin>>stuList[i].id>>stuList[i].name>>stuList[i].grade;
	}

	if( 1 == condition ){
		sort( stuList, stuList+n, cmpID );
	}else if( 2 == condition ){
		sort( stuList, stuList+n, cmpName );
	}else{
		sort( stuList, stuList+n, cmpGrade );
	}

	for( i=0; i<n; i++ ){
		cout<<setfill('0')<<setw(6)<<stuList[i].id;
		cout<<' '<<stuList[i].name<<' '<<stuList[i].grade<<'\n';
	}

	return 0;
}