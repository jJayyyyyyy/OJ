#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
	string id;
	string format_sign_in;
	string format_sign_out;
	int second_sign_in;
	int second_sign_out;
public:
	Student(string us_id, string us_sign_in, string us_sign_out){
		id = us_id;
		format_sign_in = us_sign_in;
		format_sign_out = us_sign_out;
		second_sign_in = time_to_second(format_sign_in);
		second_sign_out = time_to_second(format_sign_out);
	}
	int time_to_second(string us_time){
		int hour=0, minute=0, second=0;
		hour = (us_time[0]-'0')*10 + (us_time[1]-'0');
		minute = (us_time[3]-'0')*10 + (us_time[4]-'0');
		second = (us_time[6]-'0')*10 + (us_time[7]-'0');
		return hour*3600 + minute*60 + second;
	}
	int get_second_sign_in(){
		return second_sign_in;
	}
	int get_second_sign_out(){
		return second_sign_out;
	}
	string get_format_sign_in(){
		return format_sign_in;
	}
	string get_format_sign_out(){
		return format_sign_out;
	}
	string get_id(){
		return id;
	}
};

int cmp_dec(Student a, Student b){
	return a.get_second_sign_out() > b.get_second_sign_out();
}

int cmp_inc(Student a, Student b){
	return a.get_second_sign_in() < b.get_second_sign_in();
}

int get_first(vector<Student> stu_list){
	sort(stu_list.begin(), stu_list.end(), cmp_inc);
	cout<<stu_list[0].get_id()<<' ';

	return 0;
}

int get_last(vector<Student> stu_list){
	sort(stu_list.begin(), stu_list.end(), cmp_dec);
	cout<<stu_list[0].get_id()<<'\n';

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int us_M=0;
	cin>>us_M;

	vector<Student> stu_list;
	string us_id, us_sign_in, us_sign_out;
	for( int i=0; i<us_M; i++ ){
		cin>>us_id>>us_sign_in>>us_sign_out;
		Student stu(us_id, us_sign_in, us_sign_out);
		stu_list.push_back(stu);
	}

	get_first(stu_list);
	get_last(stu_list);
	
	return 0;
}


/*
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40


*/
