#include <iostream>
using namespace std;

class Student{
public:
	string name;
	string id;
	int score;
};

int main(){
	string t_name, t_id;
	int t_score;
	int i=0, us_N=0;
	Student *stu = new Student[2];

	cin>>us_N;
	cin>>stu[0].name>>stu[0].id>>stu[0].score;
	stu[1] = stu[0];

	for(i=1; i<us_N; i++){
		cin>>t_name>>t_id>>t_score;
		if(t_score > stu[0].score){
			stu[0].name = t_name;
			stu[0].id = t_id;
			stu[0].score = t_score;
		}
		if(t_score < stu[1].score){
			stu[1].name = t_name;
			stu[1].id = t_id;
			stu[1].score = t_score;
		}
	}

	cout<<stu[0].name<<' '<<stu[0].id<<endl;
	cout<<stu[1].name<<' '<<stu[1].id<<endl;

	delete [] stu;
	return 0;
}


/*
test case

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

*/
