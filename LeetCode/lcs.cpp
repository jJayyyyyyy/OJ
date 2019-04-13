/*
Solution of Longest Common Substring
via
https://www.geeksforgeeks.org/longest-common-substring-dp-29/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int lcs(string a, string b, int len1, int len2) { 
	int LCSuff[128][128] = {0}; 
	int result = 0;

	for( int i = 0; i <= len1; i++ ){
		for( int j = 0; j <= len2; j++ ){
			if( i == 0 || j == 0 ){
				LCSuff[i][j] = 0;
			}

			else if( a[i-1] == b[j-1] ){
				LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
				result = max(result, LCSuff[i][j]);
			}

			else{
				LCSuff[i][j] = 0;
			}
		}
	}
	return result;
}

int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);

	vector<string> word_list;

	while( !ss.eof() ){
		string word;
		getline(ss, word, ',');
		word_list.push_back(word);
	}

	string a, b;

	a = word_list[0];
	b = word_list[1];
	int len1 = a.size();
	int len2 = b.size();

	// input = bab,caba
	// a = "bab"
	// b = "caba"
	// ans = 2
	cout << lcs(a, b, len1, len2) << '\n';
	return 0;
}

