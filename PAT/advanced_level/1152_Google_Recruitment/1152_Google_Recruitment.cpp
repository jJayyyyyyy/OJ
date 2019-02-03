/*
输入 len 和 k, 还有一个数字 str, len = str.size()
求出 str 中第一个 k 位的素数

本题与以往的判断素数的题略有不同
由于 k 的最大可取 10, 使得 str 可以达到 10^10 的级别
而输入的组数较少, 且个人猜测就算是 len 大 k 大的 case, 也不是特别极端
因此不适合用 筛表法, (准确地说, 用筛表法去适配 k 时无法通过编译

而用最基本的方法判断素数时, 对应本题的 case, 耗时不多
因此两种求素数的模板都需要掌握, 以便灵活运用

1. 基本方法

bool isPrime(int num)
{
	if( num == 2 )
	{
		return true;
	}

	if( num == 0 || num == 1 || num % 2 == 0 )
	{
		return false;
	}

	int up_bound = (int)sqrt(num);
	for( int i = 3; i <= up_bound; i += 2 )
	{
		if( num % i == 0 )
		{
			return false;
		}
	}
	return true;
}

2. 筛表法, 找出MAXSIZE以内的素数, 注意MAXSIZE应为奇数

#define MAXSIZE 100003
bool primeList[MAXSIZE] = {false, false, true};

void getPrimeList(){
	for( int i = 3; i < MAXSIZE; i += 2 ){
		primeList[i] = true;
		primeList[i + 1] = false;
	}

	int upperBound = (int) sqrt(MAXSIZE);
	for( int i = 3; i < upperBound; i += 2){
		if( primeList[i] == true ){
			for( int j = i + i; j < MAXSIZE; j += i ){
				primeList[j] = false;
			}
		}
	}
}
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

bool isPrime(int num)
{
	if( num == 2 )
	{
		return true;
	}

	if( num == 0 || num == 1 || num % 2 == 0 )
	{
		return false;
	}

	int up_bound = (int)sqrt(num);
	for( int i = 3; i <= up_bound; i += 2 )
	{
		if( num % i == 0 )
		{
			return false;
		}
	}
	return true;
}

int str2num(string s)
{
	stringstream ss(s);
	int num;
	ss >> num;
	return num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len, k;
	string str;
	cin>>len>>k>>str;

	int start = 0, end = len - k;

	for( int i = start; i <= end; i++ )
	{
		string sub = str.substr(i, k);
		int num = str2num(sub);
		if( isPrime(num) )
		{
			cout << sub << '\n';		// 注意输出字符串形式的数字, 保留可能存在的前导 0
			return 0;
		}
	}
	cout<<"404\n";
	return 0;
}

