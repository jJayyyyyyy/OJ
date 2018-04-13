#include <iostream>
#include <cstdio>
using namespace std;

class student{
public:
	string name;
	string gender;
	string course;
	int grade;
	int set(string a, string b, string c, int d){
		name = a;
		gender = b;
		course = c;
		grade = d;
		return 0;
	}
};

int main(){
	student boy, girl;
	boy.set("", "M", "", 1000);
	girl.set("", "F", "", -1);
	
	string name, gender, course;
	int grade;
	int n, i;
	
	cin>>n;
	for(i=0; i<n; i++){
		cin>>name>>gender>>course>>grade;
		if(gender=="M"){
			if(grade<boy.grade){
				boy.set(name, gender, course, grade);
			}
		}else{
			if(grade>girl.grade){
				girl.set(name, gender, course, grade);
			}
		}
	}

	if( boy.name!="" && girl.name!="" ){
		cout<<girl.name<<' '<<girl.course<<'\n';
		cout<<boy.name<<' '<<boy.course<<'\n';
		cout<<girl.grade - boy.grade;
	}else if( boy.name=="" ){
		cout<<girl.name<<' '<<girl.course<<'\n';
		cout<<"Absent\n";
		cout<<"NA";
	}else if( girl.name=="" ){
		cout<<"Absent\n";
		cout<<boy.name<<' '<<boy.course<<'\n';
		cout<<"NA";
	}

	return 0;
}