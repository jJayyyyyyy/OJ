#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

struct School{
	string name;
	int cntScore, cntPeople;
};

bool cmp(School a, School b){
	if( a.cntScore != b.cntScore ){
		return a.cntScore > b.cntScore;
	}else if( a.cntPeople != b.cntPeople ){
		return a.cntPeople < b.cntPeople;
	}else{
		return a.name < b.name;
	}
}


map<string, School> schoolList;
vector<School> ansList;

string lower(string s){
	string ls = "";
	for( int i = 0; i < s.size(); i++){
		char ch = s[i];
		ls += tolower(ch);
	}
	return ls;
}

int getLevel(char ch){
	int level;
	if( ch == 'B' ){
		level = 1;
	}else if( ch == 'A' ){
		level = 2;
	}else{
		level = 3;
	}
	return level;
}

int getScore(int score, int level){
	double newScore = (double) score;
	if( level == 1 ){
		newScore = (double)score / 1.5;
	}else if( level == 3){
		newScore = (double)score * 1.5;
	}
	return (int)newScore;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	string id, name;
	int score, level;
	for( int i = 0; i < n; i++ ){
		cin>>id>>score>>name;
		level = getLevel(id[0]);
		name = lower(name);
		score = getScore(score, level);

		if( schoolList.find(name) != schoolList.end() ){
			School scl = schoolList[name];
			scl.name = name;
			scl.cntScore += score;
			scl.cntPeople++;
			schoolList.erase(name);
			schoolList[name] = scl;
		}else{
			School scl;
			scl.cntScore = score;
			scl.cntPeople = 1;
			scl.name = name;
			schoolList[name] = scl;
		}
	}


	int i = 1;
	cout<<schoolList.size()<<'\n';

	// 坑：紫金港某些机器只有vs2008，不支持c++11的 auto
	for(map<string, School>::iterator it = schoolList.begin(); it != schoolList.end(); it++ ){
		School s = it->second;
		ansList.push_back(s);
	}

	sort( ansList.begin(), ansList.end(), cmp );
	for( int i = 0; i < ansList.size(); i++ ){
		cout<<i+1<<' '<<ansList[i].name<<' '<<ansList[i].cntScore<<' '<<ansList[i].cntPeople<<'\n';;
	}

	return 0;
}
