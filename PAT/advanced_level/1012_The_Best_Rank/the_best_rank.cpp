#include <iostream>
#include <vector>
#include <algorithm>
#define MAXQUERY 2004
#define MAXSTU 1000004
using namespace std;

struct Student{
	int id;
	int grade[4];
	int set(int _id, int g1, int g2, int g3){
		id = _id;
		grade[0] = g1 + g2 + g3;
		grade[1] = g1;
		grade[2] = g2;
		grade[3] = g3;
		return 0;
	}
};

Student stu[MAXQUERY];

char course[4] = {'A', 'C', 'M', 'E'};
int rankList[MAXSTU][4] = {0};
int cur;

int cmp(Student a, Student b){
	return a.grade[cur] > b.grade[cur];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i, j, id, preID, grade1, grade2, grade3;
	cin>>n>>m;

	for( i=0; i<n; i++ ){
		cin>>id>>grade1>>grade2>>grade3;
		stu[i].set(id, grade1, grade2, grade3);
	}

	for(cur=0; cur<4; cur++){
		sort(stu, stu+n, cmp);
		id = stu[0].id;
		rankList[id][cur] = 1;
		for( i=1; i<n; i++ ){
			id = stu[i].id;
			preID = stu[i-1].id;
			if( stu[i].grade[cur] == stu[i-1].grade[cur] ){
				rankList[id][cur] = rankList[preID][cur];
			}else{
				rankList[id][cur] = i + 1;
			}
		}
	}

	for( i=0; i<m; i++ ){
		cin>>id;
		if( rankList[id][0] == 0 ){
			cout<<"N/A\n";
		}else{
			cur = 0;
			for( j=0; j<4; j++ ){
				if( rankList[id][j] < rankList[id][cur] ){
					cur = j;
				}
			}
			cout<<rankList[id][cur]<<' '<<course[cur]<<'\n';
		}
	}

	return 0;
}
