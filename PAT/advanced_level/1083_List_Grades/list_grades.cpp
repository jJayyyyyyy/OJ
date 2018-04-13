#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student{
public:
	string name;
	string id;
	int grade;
};

int cmpGrade(Student a, Student b){
	return a.grade > b.grade;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,lowerLimit, higherLimit, i, grade, cnt=0;
	cin>>n;

	Student *stuList = new Student[n];

	for( i=0; i<n; i++ ){
		cin>>stuList[i].name>>stuList[i].id>>stuList[i].grade;
	}
	cin>>lowerLimit>>higherLimit;

	sort( stuList, stuList+n, cmpGrade );

	for( i=0; i<n; i++ ){
		grade = stuList[i].grade;
		if( grade<=higherLimit && grade>=lowerLimit ){
			cout<<stuList[i].name<<' '<<stuList[i].id<<'\n';
			cnt++;
		}
	}
	if( 0 == cnt ){
		cout<<"NONE\n";
	}


	delete [] stuList;
	return 0;
}