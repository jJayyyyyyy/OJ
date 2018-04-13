#include <iostream>
#include <sstream>
using namespace std;

string num2string(int num){
	stringstream ss;
	ss << num;
	return ss.str();
}

int main(int argc, char *argv[]){
	const string num_pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	int sigma=0, i=0, len=0;
	string us_num;

	cin>>us_num;
	len = us_num.size();
	while( i<len )
		sigma += (us_num[i++] - '0');

	us_num = num2string(sigma);

	len = us_num.size()-1;
	for(i=0; i<len; i++)
		cout<<num_pinyin[us_num[i] - '0']<<' ';
	cout<<num_pinyin[us_num[i] - '0'];

	return 0;
}
