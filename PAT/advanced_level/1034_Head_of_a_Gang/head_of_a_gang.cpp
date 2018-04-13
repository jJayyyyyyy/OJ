#include <iostream>
#include <string>
#include <map>
#define MAXSIZE 2004
using namespace std;

int k=0, cntID=0;
int G[MAXSIZE][MAXSIZE] = {0};
int weightList[MAXSIZE] = {0};
map<string, int> gang;
map<string, int> name2ID;
string id2Name[MAXSIZE];
bool marked[MAXSIZE] = {false};

int DFS(int idNow, int & idHead, int & cntMember, int & totalWeight){
	++cntMember;
	marked[idNow] = true;
	if( weightList[idNow] > weightList[idHead] ){
		idHead = idNow;
	}

	for( int i=0; i<cntID; ++i ){
		if( G[idNow][i] > 0 ){
			totalWeight += G[idNow][i];
			G[idNow][i] = G[i][idNow] = 0;
			if( marked[i] == false ){
				DFS( i, idHead, cntMember, totalWeight );
			}
		}
	}
	return 0;
}

int DFSTraverse(){
	for( int i=0; i<cntID; ++i ){
		if( marked[i] == false ){
			int idHead=i, cntMember=0, totalWeight=0;
			DFS( i, idHead, cntMember, totalWeight );
			if( cntMember > 2 && totalWeight > k ){
				gang[ id2Name[idHead] ] = cntMember;
			}
		}
	}
	return 0;
}

int getID(string name){
	if( name2ID.find(name) != name2ID.end() ){
		return name2ID[name];
	}else{
		name2ID[name] = cntID;
		id2Name[cntID] = name;
		return cntID++;
	}
}

int main(){
	int n, i, weight, id1, id2;
	string s1, s2;
	cin>>n>>k;

	for( i=0; i<n; ++i ){
		cin>>s1>>s2>>weight;
		id1 = getID(s1);
		id2 = getID(s2);
		weightList[id1] += weight;
		weightList[id2] += weight;
		G[id1][id2] += weight;
		G[id2][id1] += weight;
	}

	DFSTraverse();

	cout<<gang.size()<<'\n';
	map<string, int>::iterator it;
	for( it=gang.begin(); it!=gang.end(); ++it ){
		cout<<it->first<<' '<<it->second<<'\n';
	}

	return 0;
}