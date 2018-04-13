#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> win;

int main(){
	string nickname;
	int m, step, s, start, i;
	cin>>m>>step>>s;
	start = s;
	
	for( i = 1; i <= m; ++i ){
		cin>>nickname;
		if( i == start ){
			if( win.find(nickname) == win.end() ){
				cout<<nickname<<'\n';
				win.insert(nickname);
				start += step;
			}else{
				start++;
			}
		}
	}
	if( s > m ){
		cout<<"Keep going...\n";
		return 0;
	}
	return 0;
}