#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAXAPPLICANTS 40004
#define MAXSCHOOL 104
#define MAXPRERENCE 8
using namespace std;

struct Student{
	int id, rank, gradeE, gradeI, gradeFinal;
	int preference[MAXPRERENCE];
	Student(){
		id = rank = gradeE = gradeI = -1;
	}
	int setter(int _id, int _gradeE, int _gradeI){
		id = _id;
		gradeE = _gradeE;
		gradeI = _gradeI;
		gradeFinal = gradeE + gradeI;
		return 0;
	}
	
	int getInfo(int k){
		cout<<"rank: "<<rank<<'\t';
		cout<<"id: "<<id<<'\t';
		cout<<"gradeFinal: "<<gradeFinal<<'\t';
		cout<<"gradeE: "<<gradeE<<'\t';
		cout<<"gradeI: "<<gradeI<<'\t';
		cout<<"preference:";
		for( int i=0; i<k; i++ ){
			cout<<' '<<preference[i];
		}
		cout<<'\n';
		return 0;
	}
};

struct School{
	int quota;
	int rankLimit;
	set<int> stuID;
	School(){
		quota = rankLimit = 0;
	}
};

Student stuList[MAXAPPLICANTS];
School schoolList[MAXSCHOOL];

int cmp(const Student &a, const Student &b){
	if( a.gradeFinal != b.gradeFinal ){
		return a.gradeFinal > b.gradeFinal;
	}else{
		return a.gradeE > b.gradeE;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, i, j, gradeE, gradeI;
	
	cin>>n>>m>>k;
	for( i=0; i<m; i++ ){
		cin>>schoolList[i].quota;
	}
	for( i=0; i<n; i++ ){
		cin>>gradeE>>gradeI;
		stuList[i].setter(i, gradeE, gradeI);
		for( j=0; j<k; j++ ){
			cin>>stuList[i].preference[j];
		}
	}

	sort(stuList, stuList+n, cmp);

	stuList[0].rank = 0;
	for( i=0; i<n; i++ ){
		if( stuList[i].gradeFinal < stuList[i-1].gradeFinal ){
			stuList[i].rank = stuList[i-1].rank + 1;
		}else if( stuList[i].gradeE < stuList[i-1].gradeE ){
			stuList[i].rank = stuList[i-1].rank + 1;
		}else{
			stuList[i].rank = stuList[i-1].rank;
		}
	}

	// for( i=0; i<n; i++ ){
	// 	stuList[i].getInfo(k);
	// }

	int rank, id, iSchool;
	for( i=0; i<n ; i++ ){
		rank = stuList[i].rank;
		id = stuList[i].id;
		for( j=0; j<k; j++ ){
			int iSchool = stuList[i].preference[j];
			if( schoolList[iSchool].quota > 0 ){
				schoolList[iSchool].stuID.insert(id);
				schoolList[iSchool].rankLimit = rank;
				schoolList[iSchool].quota--;
				break;
			}else if( stuList[i].rank == schoolList[iSchool].rankLimit  ){
					schoolList[iSchool].stuID.insert(id);
					break;
			}
		}
	}

	int isFirst=1;
	for( i=0; i<m; i++ ){
		set<int> stuID = schoolList[i].stuID;
		set<int>::iterator it;
		for( it=stuID.begin(); it!=stuID.end(); it++ ){
			if( isFirst ){
				cout<<*it;
				isFirst = 0;
			}else{
				cout<<' '<<*it;
			}
		}
		cout<<'\n';
		isFirst = 1;
	}

	return 0;
}
