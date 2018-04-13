#include <iostream>
#include <algorithm>
using namespace std;

int get_p(const char a, const int cnt){
	int t_p=0, t_a=a-'0', t_cnt = cnt;
	while(t_cnt--)
		t_p = t_p*10 + t_a;
	return t_p;
}

int main(int argc, char *argv[]){
	string A, B;
	char a, b;
	int cnt_a=0, cnt_b=0, p_a=0, p_b=0;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>A>>a>>B>>b;

	cnt_a = count(A.begin(), A.end(), a);
	cnt_b = count(B.begin(), B.end(), b);

	p_a = get_p( a, cnt_a );
	p_b = get_p( b, cnt_b );

	cout<<p_a+p_b;

	return 0;
}
