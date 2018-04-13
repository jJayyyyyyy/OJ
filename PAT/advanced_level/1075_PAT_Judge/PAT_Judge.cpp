#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAXSIZE 10004
using namespace std;

struct Student{
	int id = 0;
	int score[8] = {-2, -2, -2, -2, -2, -2, -2, -2};
	int totalScore = -2;
	int cntPerfect = 0;
};

Student stu[MAXSIZE];
int fullMark[8];

int getTotalScore(int n, int k){
	for( int uid = 1; uid <= n; ++uid ){
		bool isFirst = true;
		for( int i = 1; i <= k; ++i ){
			int s = stu[uid].score[i];
			if( s >= 0 ){
				if( isFirst ){
					isFirst = false;
					stu[uid].totalScore = 0;
				}
				stu[uid].totalScore += s;
				if( s == fullMark[i] ){
					stu[uid].cntPerfect++;
				}
			}
		}
	}
	return 0;
}

int cmp(Student a, Student b){
	if( a.totalScore != b.totalScore ){
		return a.totalScore > b.totalScore;
	}else if( a.cntPerfect != b.cntPerfect ) {
		return a.cntPerfect > b.cntPerfect;
	}else{
		return a.id < b.id;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, m, i, j, uid, pid, mark;
	cin>>n>>k>>m;

	// init(n)
	for( int uid = 1; uid <= n; ++uid ){
		stu[uid].id = uid;
	}

	for( i = 1; i <= k; ++i ){
		cin>>fullMark[i];
	}

	for( i = 1; i <= m; ++i ){
		cin>>uid>>pid>>mark;
		if( stu[uid].score[pid] < mark ){
			stu[uid].score[pid] = mark;
		}
	}
	getTotalScore(n, k);
	sort(stu + 1, stu + n + 1, cmp);
	
	int rank = 1;
	for( i = 1; i <= n; ++i ){
		if( stu[i].totalScore < stu[i-1].totalScore ){
			rank = i;
		}
		cout<<rank<<' ';
		cout<<setfill('0')<<setw(5)<<stu[i].id;
		cout<<' '<<stu[i].totalScore;
		for( j = 1; j <= k; ++j ){
			int s = stu[i].score[j];
			if( s == -2 ){
				cout<<" -";
			}else if( s == -1 ){
				cout<<" 0";
			}else{
				cout<<' '<<s;
			}
		}
		cout<<"\n";
		if( stu[i+1].totalScore < 0 ){
			break;
		}
	}
	return 0;
}

/*

7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0



*/