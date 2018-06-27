#include <iostream>
#include <algorithm>
#define MAXSIZE 10004
using namespace std;

int diffList[MAXSIZE] = {0};

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	cin>>n;

	int face, back;
	for( int i = 0; i < n; i++ ){
		face = i + 1;
		cin>>back;
		diffList[i] = abs(face - back);
	}

	sort(diffList, diffList + n, cmp);

	diffList[n] = -1;
	
	int cnt = 1;
	for( int i = 1; i <= n; i++ ){
		if( diffList[i] != diffList[i - 1] ){
			if( cnt > 1 ){
				cout<<diffList[i - 1]<<' '<<cnt<<'\n';
			}
			cnt = 1;
		}else{
			cnt++;
		}
	}

	return 0;
}

/*
注意一个天坑:
若某个差值只出现一次, 则该行不输出 (详见 L30~L32 )
怪不得输出样例里面没有1 1 (审题要仔细)

参考: 柳神博客
https://www.liuchuo.net/archives/4644

原题如下:

1083 是否存在相等的差（20 分）
给定 N 张卡片，正面分别写上 1、2、……、N，然后全部翻面，洗牌，在背面分别写上 1、2、……、N。将每张牌的正反两面数字相减（大减小），得到 N 个非负差值，其中是否存在相等的差？

输入格式：
输入第一行给出一个正整数 N（2 ≤ N ≤ 10 000），随后一行给出 1 到 N 的一个洗牌后的排列，第 i 个数表示正面写了 i 的那张卡片背面的数字。

输出格式：
按照“差值 重复次数”的格式从大到小输出重复的差值及其重复的次数，每行输出一个结果。

输入样例：
8
3 5 8 6 2 1 4 7

输出样例：
5 2
3 3
2 2

*/