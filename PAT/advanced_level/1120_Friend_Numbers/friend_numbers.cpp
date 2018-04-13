#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<string> raw_list;
set<int> ans_set;
vector<int> ans_list;

void get_digit_sum(string num){
	int len = num.size();
	int sum = 0, digit;
	for( int i = 0; i < len; i++ ){
		digit = num[i] - '0';
		sum += digit;
	}
	// 4
	ans_set.insert(sum);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total;
	string num;

	// 1, 2
	cin>>total;
	for( int i = 0; i < total; i++ ){
		cin>>num;
		raw_list.push_back(num);
	}

	// 3
	for( auto num : raw_list ){
		get_digit_sum(num);
	}

	// 5
	for( auto ans : ans_set ){
		ans_list.push_back(ans);
	}

	// 6
	int len = ans_list.size();
	cout<<len<<'\n';
	cout<<ans_list[0];
	for( int i = 1; i < len; i++ ){
		cout<<' '<<ans_list[i];
	}
	cout<<'\n';
	return 0;
}
