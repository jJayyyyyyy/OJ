#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int get_digit_sum(string str_num)
{
	int len = str_num.size();
	int sum = 0;
	for( int i = 0; i < len; i++ )
	{
		int digit = str_num[i] - '0';
		sum += digit;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ttl_cnt;
	string str_num;

	vector<string> input_list;

	cin >> ttl_cnt;
	for( int i = 0; i < ttl_cnt; i++ )
	{
		cin >> str_num;
		input_list.push_back(str_num);
	}

	set<int> s;
	for( auto str_num : input_list )
	{
		int num = get_digit_sum(str_num);
		s.insert(num);
	}

	int len = s.size();
	cout << len << '\n';
	bool is_fitst = true;
	for( set<int>::iterator it = s.begin(); it != s.end(); it++ )
	{
		if( is_fitst == true )
		{
			cout << *it;
			is_fitst = false;
		}
		else
		{
			cout << ' ' << *it;
		}
	}

	cout<<'\n';
	return 0;
}
