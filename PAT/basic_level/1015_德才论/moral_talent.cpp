#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
public:
	int id;
	int moral;
	int talent;
	int sum;
	int print_info(){
		cout<<id<<' '<<moral<<' '<<talent<<'\n';
		return 0;
	}
	Student(int us_id, int us_moral, int us_talent, int us_sum){
		id = us_id;
		moral = us_moral;
		talent = us_talent;
		sum = us_sum;
	}
};

int cmp(const Student stu1, const Student stu2){
	if(stu1.sum != stu2.sum)
		return stu1.sum > stu2.sum;
	else if(stu1.moral != stu2.moral)
		return stu1.moral > stu2.moral;
	else
		return stu1.id < stu2.id;
}

int main(int argc, char * argv[]){
	vector<Student> stu_a, stu_b, stu_c, stu_d;
	vector<Student>::iterator iter;
	int us_num=0, us_low=0, us_high=0;
	int id=0, moral=0, talent=0, sum=0;
	int i=0;

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>us_num>>us_low>>us_high;

	for(i=0; i<us_num; i++){
		cin>>id>>moral>>talent;
		sum = moral + talent;
		if( moral<us_low || talent<us_low )
			continue;
		else{
			Student stu(id, moral, talent, sum);
			if( moral>=us_high && talent>=us_high )
				stu_a.push_back(stu);
			else if( moral>=us_high && talent<us_high )
				stu_b.push_back(stu);
			else if( moral<us_high && talent<=moral )
				stu_c.push_back(stu);
			else
				stu_d.push_back(stu);
		}
	}

	sort(stu_a.begin(), stu_a.end(), cmp);
	sort(stu_b.begin(), stu_b.end(), cmp);
	sort(stu_c.begin(), stu_c.end(), cmp);
	sort(stu_d.begin(), stu_d.end(), cmp);

	cout << stu_a.size() + stu_b.size() + stu_c.size() + stu_d.size() << '\n';

	for( iter=stu_a.begin(); iter!=stu_a.end(); iter++ )
		iter->print_info();

	for( iter=stu_b.begin(); iter!=stu_b.end(); iter++ )
		iter->print_info();

	for( iter=stu_c.begin(); iter!=stu_c.end(); iter++ )
		iter->print_info();

	for( iter=stu_d.begin(); iter!=stu_d.end(); iter++ )
		iter->print_info();

	return 0;
}
