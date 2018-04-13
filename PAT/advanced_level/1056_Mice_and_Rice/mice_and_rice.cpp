#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class MOUSE{
private:
	int mWeight;
	int mRound;
public:
	MOUSE(int _weight){
		mWeight = _weight;
		mRound = 0;
	}
	void incRound(){
		++mRound;
	}
	int getWeight(){
		return mWeight;
	}
	int getRound(){
		return mRound;
	}
};

vector<MOUSE> mice;
int order[1004];

int getIdOfMaxWeight(vector<int> idList){
	int len = idList.size();
	int i, maxId=idList[0], maxWeight=mice[ idList[0] ].getWeight();
	for( i=0; i<len; ++i ){
		int id = idList[i];
		int weight = mice[id].getWeight();
		if( maxWeight<weight ){
			maxWeight = weight;
			maxId = id;
		}
	}

	mice[maxId].incRound();
	return maxId;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int np, ng, i, j, k, weight;

	cin>>np>>ng;
	for( i=0; i<np; ++i ){
		cin>>weight;
		MOUSE mouse(weight);
		mice.push_back(mouse);
	}

	for( i=0; i<np; ++i ){
		cin>>order[i];
	}

	int sizeOfEveryRound = np;
	vector<int> vecSizeOfEveryRound;
	while(1){
		i = 0;
		vector<int> maxIdList;
		for( j=0; j<(sizeOfEveryRound/ng); j++ ){
			vector<int> idList;
			int maxId;
			for( k=0; k<ng; k++ ){
				idList.push_back( order[i++] );
			}
			maxId = getIdOfMaxWeight(idList);
			maxIdList.push_back(maxId);
		}

		if(sizeOfEveryRound%ng){
			for( j=0; j<1; j++){
				vector<int> idList;
				int maxId;
				for( k=0; k<(sizeOfEveryRound%ng); k++ ){
					idList.push_back( order[i++] );
				}
				maxId = getIdOfMaxWeight(idList);
				maxIdList.push_back(maxId);
			}
		}

		sizeOfEveryRound = maxIdList.size();
		vecSizeOfEveryRound.push_back(sizeOfEveryRound);
		for( i=0; i<sizeOfEveryRound; ++i ){
			order[i] = maxIdList[i];
			// cout<< mice[ order[i] ].getWeight() <<' ';
		}

		if( sizeOfEveryRound==1 ){
			break;
		}
	}

	int totalRound = vecSizeOfEveryRound.size();

	// cout<<totalRound<<endl;

	// for( i=0; i<vecSizeOfEveryRound.size(); i++ ){
	// 	cout<<vecSizeOfEveryRound[i]<<' ';
	// }
	// cout<<endl;

	// for( i=0; i<np; ++i ){
	// 	cout<< mice[i].getRound()<< ' ';
	// }
	// cout<<endl;

	int isFirst = 1;
	for( i=0; i<np; ++i ){
		int iRound = mice[i].getRound();
		if(isFirst){
			isFirst = 0;
		}else{
			cout<<' ';
		}

		if( iRound<totalRound ){
			cout<< 1 + vecSizeOfEveryRound[iRound] ;
		}else{
			cout<< 1 ;
		}
		

	}
	cout<<'\n';


	return 0;
}