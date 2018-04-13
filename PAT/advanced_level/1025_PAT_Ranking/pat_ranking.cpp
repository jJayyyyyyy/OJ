#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct Student{
	long long id;
	int score, location, localRank, globalRank;
	int set(long long _id, int _score, int _location){
		id = _id;
		score = _score;
		location = _location;
		localRank = 1;
		globalRank = 1;
		return 0;
	}
};

vector<Student> stuAll;

int cmp(Student a, Student b){
	if( a.score != b.score ){
		return a.score > b.score;
	}else{
		return a.id < b.id;
	}
}

int getInfo(int i, int globalRank){
	cout<<setfill('0')<<setw(13)<<stuAll[i].id<<' '<<globalRank<<' '<<stuAll[i].location<<' '<<stuAll[i].localRank<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, k;
	long long id;
	int score, location;

	cin>>n;
	
	for( location=1; location<=n; location++ ){
		cin>>k;
		vector<Student> stuPart(k);
		
		for( i=0; i<k; i++ ){
			cin>>id>>score;
			stuPart[i].set(id, score, location);
		}
		
		sort(stuPart.begin(), stuPart.end(), cmp);

		int localRank = 1;
		stuPart[0].localRank = localRank;
		stuAll.push_back(stuPart[0]);

		for( i=1; i<k; i++ ){
			if( stuPart[i].score < stuPart[i-1].score ){
				localRank = i + 1;
			}
			stuPart[i].localRank = localRank;
			stuAll.push_back(stuPart[i]);
		}
	}

	sort(stuAll.begin(), stuAll.end(), cmp);

	int len = stuAll.size();
	cout<<len<<'\n';

	int globalRank = 1;
	getInfo(0, globalRank);

	for( i=1; i<len; i++ ){
		if( stuAll[i].score < stuAll[i-1].score ){
			globalRank = i + 1;
		}
		getInfo(i, globalRank);
	}

	return 0;
}

