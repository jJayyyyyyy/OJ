#include <iostream>
#include <string>
using namespace std;

class Numb{
private:
	string sigDigits;
	int posiDecimal;
	int sigDigitLen;
	int expo;
public:
	Numb(string strNum, int n){
		if( strNum == "." || strNum == "0" ){
			// num == 0
			string zero(n, '0');
			sigDigits = zero;
			expo = 0;
		}else if( strNum[0]=='.' && strNum.size()>1 ){
			// 0<num<1
			strNum = strNum.substr(1);
			int firstIdxOfNonZero = strNum.find_first_not_of('0');
			sigDigits = strNum.substr(firstIdxOfNonZero);
			expo = -firstIdxOfNonZero;
			sigDigitLen = sigDigits.size();
			if( sigDigitLen<n ){
				sigDigits.insert( sigDigitLen, n - sigDigitLen, '0' );
			}else{
				sigDigits.erase( n, sigDigitLen - n );
			}
		}else{
			// num >= 1
			posiDecimal = strNum.find('.');
			
			if( posiDecimal==string::npos ){
				// no decimal
				sigDigits = strNum;
				sigDigitLen = sigDigits.size();
				expo = sigDigitLen;
			}else{
				// has decimal
				sigDigits = strNum.erase( posiDecimal, 1 );
				sigDigitLen = sigDigits.size();
				expo = posiDecimal;
			}

			if( sigDigitLen<n ){
				sigDigits.insert( sigDigitLen, n - sigDigitLen, '0' );
			}else{
				sigDigits.erase( n, sigDigitLen - n );
			}
		}
	}

	string getSigDigit(){
		return sigDigits;
	}

	int getExpo(){
		return expo;
	}
};

int stripZero(string &s){
	int preZero = s.find_first_not_of('0');
	if( preZero==string::npos ){
		s = "0";
		return 0;
	}else{
		s.erase( 0, preZero );
		if( s.find('.')!=string::npos ){
			int postZero = s.find_last_not_of('0');
			if( postZero==s.size() || postZero==string::npos ){
				// no postZero
			}else{
				// has postZero
				s.erase( postZero+1, s.size() );
			}
		}
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s1, s2;
	cin>>n>>s1>>s2;
	stripZero(s1);
	stripZero(s2);
	
	Numb num1( s1, n ), num2( s2, n );

	string sigDigit1 = num1.getSigDigit();
	int expo1 = num1.getExpo();

	string sigDigit2 = num2.getSigDigit();
	int expo2 = num2.getExpo();

	if( expo1==expo2 && sigDigit1==sigDigit2 ){
		cout<<"YES";
		cout<<" 0."<<sigDigit1<<"*10^"<<expo1;
	}else{
		cout<<"NO";
		cout<<" 0."<<sigDigit1<<"*10^"<<expo1;
		cout<<" 0."<<sigDigit2<<"*10^"<<expo2;
	}

	return 0;
}


/*

3 12345 12344.5
5 123.4 123456.7
4 123.4 123456.7
5 123.4 123456.7

3 12345.6 12345.6
3 0 0
3 0.1 0.12

4 0000 0000.00
4 00123.5678 0001235
3 0.0520 0.0521
4 00000.000000123 0.0000001230
4 00100.00000012 100.00000013
5 0010.013 10.012
4 123.5678 123.5
3 123.5678 123
4 123.0678 123
3 0.000 0

*/