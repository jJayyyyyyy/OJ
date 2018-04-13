#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAX 100004
using namespace std;

struct Student{
	int id, virtue, talent, total;
	int set(int _id, int _virtue, int _talent){
		id = _id;
		virtue = _virtue;
		talent = _talent;
		total = virtue + talent;
		return 0;
	}
	int getInfo(){
		cout<<id<<' '<<virtue<<' '<<talent<<'\n';
		return 0;
	}
};

Student stuListA[MAX];
Student stuListB[MAX];
Student stuListC[MAX];
Student stuListD[MAX];

int cmp(Student a, Student b){
	if( a.total != b.total ){
		return a.total > b.total;
	}else{
		if( a.virtue != b.virtue ){
			return a.virtue > b.virtue;
		}else{
			return a.id < b.id;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, low, high, i;
	int m=0, a=0, b=0, c=0, d=0;
	int id, virtue, talent;
	cin>>n>>low>>high;

	for( i=0; i<n; i++ ){
		cin>>id>>virtue>>talent;
		if( virtue>=low && talent>=low ){
			m++;
			if( virtue>=high && talent>=high ){
				stuListA[a++].set(id, virtue, talent);
			}else if( virtue>=high && talent<high ){
				stuListB[b++].set(id, virtue, talent);
			}else if( virtue>=talent ){
				stuListC[c++].set(id, virtue, talent);
			}else{
				stuListD[d++].set(id, virtue, talent);
			}
		}
	}

	sort(stuListA, stuListA + a, cmp);
	sort(stuListB, stuListB + b, cmp);
	sort(stuListC, stuListC + c, cmp);
	sort(stuListD, stuListD + d, cmp);

	cout<<m<<'\n';
	for( i=0; i<a; i++ ){
		stuListA[i].getInfo();
	}
	for( i=0; i<b; i++ ){
		stuListB[i].getInfo();
	}
	for( i=0; i<c; i++ ){
		stuListC[i].getInfo();
	}
	for( i=0; i<d; i++ ){
		stuListD[i].getInfo();
	}
	return 0;
}
