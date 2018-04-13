#include <iostream>
#include <set>
using namespace std;

class MEMBER{
private:
	set<int> children;
	int height;
public:
	MEMBER(){
		height = 1;
	}
	int addChild(int childID){
		children.insert(childID);
		return 0;
	}
	int hasChildren(){
		return children.size();
	}
	set<int> getChildren(){
		return children;
	}
	int incHeight(){
		height++;
		return 0;
	}
	int getHeight(){
		return height;
	}
};

MEMBER family[128];

int updateHeight(int parentID){
	if( 0==family[parentID].hasChildren() ){
		return 0;
	}else{
		set<int> children = family[parentID].getChildren();
		set<int>::iterator childID;
		for( childID=children.begin(); childID!=children.end(); childID++ ){
			family[ *childID ].incHeight();
			updateHeight(*childID);
		}
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int totalNodes, nonLeaf;
	cin>>totalNodes>>nonLeaf;

	int parentID, cntChildren, childrenID, i, j;
	for( i=1; i<=nonLeaf; i++ ){
		cin>>parentID>>cntChildren;
		for( j=0; j<cntChildren; j++ ){
			cin>>childrenID;
			family[parentID].addChild(childrenID);
		}
	}

	for( i=1; i<=totalNodes; i++ ){
		updateHeight(i);
	}
	

	int leaves[128] = {0};
	int maxGeneration = 0;
	for( i=1; i<=totalNodes; i++ ){
		int generation = family[i].getHeight();
		if( 0==family[i].hasChildren() ){
			leaves[ generation ] ++;
		}
		if( generation > maxGeneration ){
			maxGeneration = generation;
		}
	}

	int isFirst = 1;
	for( i=1; i<=maxGeneration; i++ ){
		if( isFirst ){
			isFirst = 0;
			cout<<leaves[i];
		}else{
			cout<<' '<<leaves[i];
		}
	}

	return 0;
}