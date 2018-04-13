#include <iostream>
#include <string>
#include <algorithm>
#define MAXSIZE 100004
#define MAXAGE 204
using namespace std;

struct Person{
	string name;
	int age, worth;
	int set(string _name, int _age, int _worth){
		name = _name;
		age = _age;
		worth = _worth;
		return 0;
	}
	int getInfo(){
		cout<<name<<' '<<age<<' '<<worth<<'\n';
		return 0;
	}
};
Person person[MAXSIZE];
Person validPerson[MAXSIZE];
int ageList[MAXAGE] = {0};

int cmp(Person a, Person b){
	if( a.worth != b.worth ){
		return a.worth > b.worth;
	}else if( a.age != b.age ){
		return a.age < b.age;
	}else{
		return a.name < b.name;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string name;
	int n, k, i, j, age, worth, maxOutput, amin, amax;
	cin>>n>>k;

	for( i = 0; i < n; ++i ){
		cin>>name>>age>>worth;
		person[i].set(name, age, worth);
	}
	sort(person, person + n, cmp);

	int validNum = 0;
	for( i = 0; i < n; ++i ){
		age = person[i].age;
		if( ageList[age] < 100 ){
			ageList[age]++;
			validPerson[validNum++] = person[i];
		}
	}

	for( i = 1; i <= k; ++i ){
		cin>>maxOutput>>amin>>amax;
		cout<<"Case #"<<i<<':'<<'\n';
		int cntOutput = 0;
		for( j = 0; j < validNum && cntOutput < maxOutput; ++j ){
			if( validPerson[j].age >= amin && validPerson[j].age <= amax ){
				validPerson[j].getInfo();
				++cntOutput;
			}
		}
		if( cntOutput == 0 ){
			cout<<"None\n";
		}
	}
	return 0;
}
