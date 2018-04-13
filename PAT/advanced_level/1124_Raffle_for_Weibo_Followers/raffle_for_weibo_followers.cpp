#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<string> raw_list, winner_list;
set<string> winner_set;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total, step, start;
	string name;

	// 1.
	cin>>total>>step>>start;
	raw_list.push_back("none"); // 占位0
	for( int i = 0; i < total; i++ ){
		cin>>name;
		raw_list.push_back(name);
	}

	// 2.
	if( start > total ){
		cout<<"Keep going...\n";
		return 0;
	}
	
	// 3.
	for( int ix=start; ix<=total; ){
		name = raw_list[ix];
		if( winner_set.find(name) == winner_set.end() ){
			winner_list.push_back(name);
			winner_set.insert(name);
			ix += step;
		}else{
			ix += 1;
		}
	}
	
	// 4.
	for( auto & name : winner_list ){
		cout<<name<<'\n';
	}
	return 0;
}
