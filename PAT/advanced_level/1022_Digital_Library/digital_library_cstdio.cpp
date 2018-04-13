#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set<string> > mTitle, mAuthor, mKeyword, mPublisher, mYear;
set<string>::iterator it;

int search(set<string> &qWord){
	if( qWord.size()==0 ){
		cout<<"Not Found\n";
		return 0;
	}

	for( it=qWord.begin(); it!=qWord.end(); it++ ){
		cout<<*it<<'\n';
	}
	
	return 0;
}

int main(){
	int n, m, i;
	string id, title, author, keyword, publisher, year;

	cin>>n;
	getchar();
	for(i=0; i<n; i++){
		//get book info

		// get id
		getline(cin, id);

		// get title
		getline(cin, title);
		mTitle[title].insert(id);
		
		// get author
		getline(cin, author);
		mAuthor[author].insert(id);
	
		// get keyword(s)
		while(1){
			cin>>keyword;
			mKeyword[keyword].insert(id);
			if( getchar()=='\n' ){
				break;
			}
		}

		// get publisher
		getline(cin, publisher);
		mPublisher[publisher].insert(id);

		// get year
		getline(cin, year);
		mYear[year].insert(id);
	}

	cin>>m;
	getchar();
	char qType;
	string qWord;
	for(i=0; i<m; i++){
		//get user input
		qType = getchar();
		getchar();
		getchar();
		getline(cin, qWord);
		cout<<qType<<": "<<qWord<<'\n';
		if( qType=='1' ){
			// search Title
			search(mTitle[qWord]);
		}else if( qType=='2' ){
			// search author
			search(mAuthor[qWord]);
		}else if( qType=='3' ){
			// search keyword
			search(mKeyword[qWord]);
		}else if( qType=='4' ){
			// search publisher
			search(mPublisher[qWord]);
		}else{
			// search year
			search(mYear[qWord]);
		}

	}

	return 0;
}
