#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> course[2504];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name;
	int i, j, id, C, size, numStudent, totalCourse;
	cin>>numStudent>>totalCourse;
	
	for( i = 0; i < numStudent; ++i ){
		cin>>name>>C;
		for( j = 0; j < C; ++j ){
			cin>>id;
			course[id].push_back(name);
		}
	}

	for( id = 1; id <= totalCourse; ++id ){
		sort(course[id].begin(), course[id].end());
		size = course[id].size();
		cout<<id<<' '<<size<<'\n';
		for( j = 0; j < size; ++j ){
			cout<<course[id][j]<<'\n';
		}
	}

	return 0;
}