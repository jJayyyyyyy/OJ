#include <iostream>

using namespace std;
int main(){
	int num;
	cin>>num;

	int mid, left, right, expo=1, ans=0;
	while( num / expo ){
		left = num / (expo * 10);
		mid = (num / expo) % 10;
		right = num % expo;
		if( 0 == mid ){
			ans += left * expo;
		}else if( 1 == mid ){
			ans += left*expo + right + 1;
		}else{
			ans += (left + 1)*expo;
		}
		expo *= 10;
	}
	cout<<ans;
	return 0;
}