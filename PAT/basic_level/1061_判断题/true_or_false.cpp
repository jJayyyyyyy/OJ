#include <iostream>
using namespace std;

int main(){
	int n, m, j=0, i=0;
	cin>>n>>m;
	int fullMark[104]={0};
	bool answer[104]={0}, choice[104]={0};
	int scoreOfStudent[104]={0};

	for(i=0; i<m; i++){
		cin>>fullMark[i];
	}
	for(i=0; i<m; i++){
		cin>>answer[i];
	}
	for(j=0; j<n; j++){
		for(i=0; i<m; i++){
			cin>>choice[i];
			if( choice[i]==answer[i] )
				scoreOfStudent[j] += fullMark[i];
		}
	}

	for(j=0; j<n; j++){
		cout<<scoreOfStudent[j]<<'\n';
	}

	return 0;
}
