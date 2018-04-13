#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define MAXSIZE 10004
using namespace std;

struct Person{
	int id;
	vector<int> coFriendList;
};

struct Contact{
	int con1, con2;
	Contact(int a, int b){
		con1 = a;
		con2 = b;
	}
};

Person personList[MAXSIZE];
// personMatrix
bool matrix[MAXSIZE][MAXSIZE] = {false};

int cmp(Contact a, Contact b){
	if( a.con1 != b.con1 ){
		return a.con1 < b.con1;
	}else{
		return a.con2 < b.con2;
	}
}

void check_contact(int id1, int id2){
	id1 = abs(id1);
	id2 = abs(id2);
	vector<Contact> ansList;
	for(auto & con1 : personList[id1].coFriendList){
		if( con1 != id2 ){
			for( auto & con2 : personList[id2].coFriendList ){
				if( matrix[con1][con2] == true ){
					if( con2 != id1 ){
						ansList.push_back(Contact(con1, con2));
					}

				}
			}
		}

	}
	sort(ansList.begin(), ansList.end(), cmp);

	// show ansList
	int len = ansList.size();
	cout<<len<<'\n';
	for( int i = 0; i < len; i++ ){
		cout<<setw(4)<<setfill('0')<<ansList[i].con1<<' ';
		cout<<setw(4)<<setfill('0')<<ansList[i].con2<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, total_rel, i, id1, id2;
	cin>>n>>total_rel;
	for( i = 0; i < total_rel; i++ ){
		cin>>id1>>id2;
		if( id1 < 0 ){
			id1 = -id1;
			if( id2 < 0 ){
				id2 = -id2;

				matrix[id1][id2] = true;
				matrix[id2][id1] = true;
				personList[id1].coFriendList.push_back(id2);
				personList[id2].coFriendList.push_back(id1);
			}else{
				matrix[id1][id2] = true;
				matrix[id2][id1] = true;
			}
		}else{
			if( id2 < 0 ){
				id2 = -id2;

				matrix[id1][id2] = true;
				matrix[id2][id1] = true;
			}else{

				matrix[id1][id2] = true;
				matrix[id2][id1] = true;
				personList[id1].coFriendList.push_back(id2);
				personList[id2].coFriendList.push_back(id1);
			}
		}
	}

	int total_query;
	cin>>total_query;
	for( i = 0; i < total_query; i++ ){
		cin>>id1>>id2;
		check_contact(id1, id2);
	}

	return 0;
}