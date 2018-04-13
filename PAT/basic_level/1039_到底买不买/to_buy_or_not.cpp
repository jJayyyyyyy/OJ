#include <iostream>
#include <string>
using namespace std;

int main(){
	string s1, s2;
	int len1, len2;
	int offer[160]={0}, need[160]={0};
	int i, cnt_excess=0, cnt_lack=0, is_ok=1;

	cin>>s1>>s2;
	len1 = s1.size();
	len2 = s2.size();

	char ch;
	for( i=0; i<len1; i++ ){
		ch = s1[i];
		offer[ch]++;
	}

	for( i=0; i<len2; i++ ){
		ch = s2[i];
		need[ch]++;
	}

	for( i='0'; i<='9'; i++ ){
		if( offer[i]>=need[i] ){
			cnt_excess += offer[i] - need[i];
		}else{
			is_ok = 0;
			cnt_lack += need[i] - offer[i];
		}
	}

	for( i='a'; i<='z'; i++ ){
		if( offer[i]>=need[i] ){
			cnt_excess += offer[i] - need[i];
		}else{
			is_ok = 0;
			cnt_lack += need[i] - offer[i];
		}
	}

	for( i='A'; i<='Z'; i++ ){
		if( offer[i]>=need[i] ){
			cnt_excess += offer[i] - need[i];
		}else{
			is_ok = 0;
			cnt_lack += need[i] - offer[i];
		}
	}

	if(is_ok)
		cout<<"Yes "<<cnt_excess;
	else
		cout<<"No "<<cnt_lack;

	return 0;
}

// 18min
