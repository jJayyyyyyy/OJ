#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct School{
	string name;
	int cntStu;
	double doubleScore;
	int totalScore;
};

unordered_map<string, School> schoolMap;
vector<School> ansList;

void lower(string & s){
	for( auto & ch : s ){
		ch = tolower(ch);
	}
}

int getLevel(char ch){
	int level = 0;
	if( ch == 'B' ){
		level = 1;
	}else if( ch == 'A' ){
		level = 2;
	}else{
		level = 3;
	}
	return level;
}

double getScore(double score, int level){
	double newScore = score;
	if( level == 1 ){
		newScore /= 1.5;
	}else if( level == 2){
		newScore = newScore;
	}else if( level == 3 ){
		newScore *= 1.5;
	}else{
		newScore = 0;
	}
	return newScore;
}

bool cmp(School a, School b){
	if( a.totalScore != b.totalScore ){
		return a.totalScore > b.totalScore;
	}else if( a.cntStu != b.cntStu ){
		return a.cntStu < b.cntStu;
	}else{
		return a.name < b.name;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	string id, name;
	int level;
	double score;
	for( int i = 0; i < n; i++ ){
		cin>>id>>score>>name;
		level = getLevel(id[0]);
		lower(name);
		double weighedScore = getScore(score, level);

		if( schoolMap.find(name) != schoolMap.end() ){
			School school = schoolMap[name];
			school.name = name;
			school.doubleScore += weighedScore;
			school.cntStu++;
			schoolMap.erase(name);
			schoolMap[name] = school;
		}else{
			School school;
			school.doubleScore = weighedScore;
			school.cntStu = 1;
			school.name = name;
			schoolMap[name] = school;
		}
	}


	// 坑：紫金港某些机器只有vs2008，不支持c++11的 auto
	unordered_map<string, School>::iterator it;
	for( it = schoolMap.begin(); it != schoolMap.end(); it++ ){
		School s = it->second;
		s.totalScore = (int)s.doubleScore;
		ansList.push_back(s);
	}

	sort( ansList.begin(), ansList.end(), cmp );

	cout<<ansList.size()<<'\n';
	int rank = 1;
	cout<<rank<<' '<<ansList[0].name<<' '<<ansList[0].totalScore<<' '<<ansList[0].cntStu<<'\n';

	for( int i = 1; i < ansList.size(); i++ ){
		if( ansList[i].totalScore != ansList[i - 1].totalScore ){
			rank = i + 1;
		}
		cout<<rank<<' '<<ansList[i].name<<' '<<ansList[i].totalScore<<' '<<ansList[i].cntStu<<'\n';
	}

	return 0;
}

/*
坑1: 紫金港某些机器只有vs2008，不支持c++11的 auto

坑2: 加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的【整数部分】
double doubleScore = ...;
int totalScore = (int) doubleScore;

*/