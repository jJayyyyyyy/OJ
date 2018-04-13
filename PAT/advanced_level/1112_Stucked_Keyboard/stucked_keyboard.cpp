#include <iostream>
#include <string>
using namespace std;

bool notBroken[160] = {false};
bool broken[160] = {false};
bool printed[160] = {false};

int main(){
	int k, cnt = 1;
	string s;
	cin>>k>>s;

	char pre='^', cursor;
	char end='$';
	s = s + end;
	int len = s.size();

	for( int i = 0; i < len; i++ ){
		cursor = s[i];
		if( cursor == pre ){
			cnt++;
		}else{
			if( cnt % k != 0 ){
				notBroken[pre] = true;
			}
			cnt = 1;
		}

		if( i < len - 1 ){
			if( cnt % k == 0 ){
				broken[cursor] = true;
			}
		}
		pre = cursor;
	}

	for( int i = 0; i < len; i++ ){
		cursor = s[i];
		if( notBroken[cursor] == true ){
			broken[cursor] = false;
		}
	}

	for( int i = 0; i < len; i++ ){
		cursor = s[i];
		if( broken[cursor] == true ){
			if( printed[cursor] == false ){
				cout<<cursor;
				printed[cursor] = true;
			}
		}
	}
	cout<<'\n';
	for( int i = 0; i < len-1; ){
		cursor = s[i];
		cout<<cursor;
		if( broken[cursor] == true ){
			i += k;
		}else{
			i++;
		}
	}
	cout<<'\n';
	return 0;
}
