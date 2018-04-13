#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ACCOUNT{
private:
	string username;
	string passwd;
public:
	ACCOUNT(string _username, string _passwd){
		username = _username;
		passwd = _passwd;
	}
	string getUsername(){
		return username;
	}
	string getPasswd(){
		return passwd;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, cnt, len, hasModified=0;
	string username, passwd;
	cin>>n;

	vector<ACCOUNT> accountList;
	for( i=0; i<n; i++ ){
		cin>>username>>passwd;
		len = passwd.size();

		hasModified = 0;
		for( j=0; j<len; j++ ){
			if( '1' == passwd[j] ){
				passwd[j] = '@';
				hasModified = 1;
			}else if( '0' == passwd[j] ){
				passwd[j] = '%';
				hasModified = 1;
			}else if( 'l' == passwd[j] ){
				passwd[j] = 'L';
				hasModified = 1;
			}else if( 'O' == passwd[j] ){
				passwd[j] = 'o';
				hasModified = 1;
			}else{

			}
		}
		if( 1==hasModified ){
			ACCOUNT account(username, passwd);
			accountList.push_back(account);
		}
	}

	cnt = accountList.size();
	if( 0==cnt ){
		if( 1==n ){
			cout<<"There is 1 account and no account is modified";
		}else{
			cout<<"There are "<<n<<" accounts and no account is modified";
		}
	}else{
		cout<<cnt<<'\n';
		ACCOUNT account("1", "1");
		for( i=0; i<cnt; i++ ){
			account = accountList[i];
			cout<<account.getUsername()<<' '<<account.getPasswd()<<'\n';
		}
	}

	return 0;
}