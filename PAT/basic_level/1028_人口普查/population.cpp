#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	string name;
	int birthday;
public:
	string get_name(){ return name; }
	int get_birthday(){ return birthday; }
	void set(string us_name, int us_birthday){
		name = us_name;
		birthday = us_birthday;
	}
	Person(string us_name, int us_birthday){
		name = us_name;
		birthday = us_birthday;
	}
};

int is_younger(string name, int date, Person &young){
	if( date>young.get_birthday() )
		young.set(name, date);
	return 1;
}

int is_older(string name, int date, Person &old){
	if( date<old.get_birthday() )
		old.set(name, date);
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int us_N;
	cin>>us_N;

	string us_name, us_date;
	int int_date=0, cnt_valid=0;
	Person youngest("n", 0), oldest("n", 25000000);

	for(int i=0; i<us_N; i++){
		cin>>us_name>>us_date;
		int_date = stoi( us_date.replace(4, 1, "").replace(6, 1, "") );
		if( int_date<=20140906 && int_date>=18140906 ){
			is_younger(us_name, int_date, youngest);
			is_older(us_name, int_date, oldest);
			cnt_valid++;
		}
	}

	cout<<cnt_valid;
	if(cnt_valid)
		cout<<' '<<oldest.get_name()<<' '<<youngest.get_name();


	return 0;
}
