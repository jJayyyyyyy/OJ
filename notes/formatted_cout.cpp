#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int a = 12;
	// 整数，前面补0输出
	cout<<setfill('0')<<setw(4)<<a<<'\n';

	double b = 3.141;
	// 保留n位小数
	// cout.setf(ios::fixed);
	cout<<fixed<<setprecision(4)<<b<<'\n';
	cout<<fixed<<setprecision(2)<<b<<'\n';
	return 0;
}