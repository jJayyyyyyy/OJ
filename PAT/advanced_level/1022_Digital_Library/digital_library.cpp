#include <iostream>
#include <sstream>
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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i;
	string id, title, author, keywords, keyword, publisher, year;
	string query, qType, qWord;
	string whiteline;
	

	cin>>n;
	getline(cin, whiteline);

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
		getline(cin, keywords);
		stringstream ss(keywords);
		while( !ss.eof() ){
			getline(ss, keyword, ' ');
			mKeyword[keyword].insert(id);
		}

		// get publisher
		getline(cin, publisher);
		mPublisher[publisher].insert(id);

		// get year
		getline(cin, year);
		mYear[year].insert(id);
	}

	cin>>m;
	getline(cin, whiteline);
	
	for(i=0; i<m; i++){
		//get user input
		getline(cin, qType, ' ');
		getline(cin, qWord);

		cout<<qType[0]<<": "<<qWord<<'\n';
		if( qType[0]=='1' ){
			// search Title
			search(mTitle[qWord]);
		}else if( qType[0]=='2' ){
			// search author
			search(mAuthor[qWord]);
		}else if( qType[0]=='3' ){
			// search keyword
			search(mKeyword[qWord]);
		}else if( qType[0]=='4' ){
			// search publisher
			search(mPublisher[qWord]);
		}else{
			// search year
			search(mYear[qWord]);
		}

	}

	return 0;
}
