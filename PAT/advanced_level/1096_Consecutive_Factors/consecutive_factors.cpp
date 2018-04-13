#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

class MEMBER{
private:
	set<int> children;
	int height;
public:
	MEMBER(){
		height = 1;
	}
	int addChild(int _id){
		children.insert(_id);
		return 0;
	}
	int incHeight(){
		height++;
		return 0;
	}

	int hasChildren(){
		return children.size();
	}
	set<int> getChildren(){
		return children;
	}

	int getHeight(){
		return height;
	}
};

MEMBER family[128];

int updateHeight(int parentID){
	if( 0==(family[parentID].hasChildren()) ){
		return 0;
	}else{
		set<int> children = family[parentID].getChildren();
		set<int>::iterator childID;
		for( childID=children.begin(); childID!=children.end(); childID++ ){
			family[*childID].incHeight();
			updateHeight( *childID );
		}
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cntTotal, cntHasChild, i, j;
	cin>>cntTotal>>cntHasChild;

	for( i=1; i<=cntHasChild; i++ ){
		int parentID, cntChildren;
		cin>>parentID>>cntChildren;
		for( j=0; j<cntChildren; j++ ){
			int childID;
			cin>>childID;
			family[parentID].addChild(childID);
		}
	}

	for( i=1; i<=cntTotal; i++ ){
		updateHeight( i );
	}

	int generation[128]={0};
	for( i=1; i<=cntTotal; i++ ){
		int k = family[i].getHeight();
		++ generation[k];
	}

	int maxCnt=0, maxGeneration=0;
	for( i=1; i<=cntTotal; i++ ){
		if( generation[i]>maxCnt ){
			maxCnt = generation[i];
			maxGeneration = i;
		}
	}

	cout<<maxCnt<<' '<<maxGeneration<<'\n';

	//for( i=1; i<=cntTotal; i++ ){
	//	int idMember = i;
	//	
	//	set<int> children = family[idMember].getChildren();
	//	set<int>::iterator childID;
	//	int cntChildren = children.size();
	//	int generation = family[idMember].getHeight();

	//	cout<<setfill('0')<<setw(2)<<idMember<<'\t';
	//	cout<<"height: "<<generation;
	//	cout<<"\thas "<<cntChildren<<" ch:\t";
	//	// cout<<family[idMember].getHeight()<<children.size()<<'\t';
	//	for( childID=children.begin(); childID!=children.end(); childID++ ){
	//		cout<<' '<<*childID;
	//	}
	//	cout<<'\n';
	//}

	return 0;
}