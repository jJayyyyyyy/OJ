#include <iostream>
#include <iomanip>
#define MAX 100004
using namespace std;

struct Member{
	int atParty;
	int cpAtParty;
	int cpID;
	Member(){
		atParty = cpAtParty = cpID = -1;
	}
};

Member member[MAX];
int singleList[MAX] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2, i, id1, id2, cpID, cnt=0, isFirst=1;
	
	cin>>n1;
	for( i=0; i<n1; i++ ){
		cin>>id1>>id2;
		member[id1].cpID = id2;
		member[id2].cpID = id1;
	}

	cin>>n2;
	for( i=0; i<n2; i++ ){
		cin>>id1;
		member[id1].atParty = 1;
		cpID = member[id1].cpID;
		if( -1 != cpID ){
			member[cpID].cpAtParty = 1;
		}
	}

	for( i=0; i<MAX; i++ ){
		if( 1 == member[i].atParty ){
			if( -1 == member[i].cpID ){
				// cout<<"member "<<i<<" has no cp\n";
				singleList[cnt++] = i;
			}else if( -1 == member[i].cpAtParty ){
				// cout<<"member "<<i<<"'s cp is not here\n";
				singleList[cnt++] = i;
			}
		}
	}

	cout<<cnt<<'\n';
	for( i=0; i<cnt; i++ ){
		if( isFirst ){
			cout<<setfill('0')<<setw(5)<<singleList[i];
			isFirst = 0;
		}else{
			cout<<' '<<setfill('0')<<setw(5)<<singleList[i];
		}
	}

	return 0;
}


/*

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define MAXSIZE 100004
#define None -1
using namespace std;

struct Person{
	int id, cpID;
	bool atParty, cpAtParty;
	Person(){
		id = cpID = None;
		atParty = cpAtParty = false;
	}
}

Person personList[MAXSIZE];

vector<int> coupleList(MAXSIZE, -1);
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cntCP, id1, id2;
	cin>>cntCP;
	for( int i = 0; i < cntCP; i++ ){
		cin>>id1>>id2;
		personList[id1].id = id1;
		personList[id2].id = id2;

		personList[id1].cpID = id2;
		coupleList[id2].cpID = id1;
	}

	int guestCnt;
	cin>>guestCnt;
	for( int i = 0; i < guestCnt; i++ ){
		int id, cpID;
		cin>>id;

		personList[id].atParty = true;
		
		cpID = personList[id].cpID;
		if(cpID != None){
			personList[cpID].cpAtParty = true;
		}
	}

	for( int i = 0; i < MAXSIZE; i++ ){
		if( guestList[i] == true ){
			int id = i;
			int cpid = coupleList[id];
			if( cpid == -1 || guestList[cpid] == false ){
				ans.push_back(id);
			}
		}
	}

	sort(ans.begin(), ans.end());
	int len = ans.size();

	cout<<len<<'\n';
	if( len > 0 ){
		cout<<setw(5)<<setfill('0')<<ans[0];
		for( int i = 1; i < len; i++ ){
			cout<<' '<<setw(5)<<setfill('0')<<ans[i];
		}
		cout<<'\n';
	}

	return 0;
}
*/