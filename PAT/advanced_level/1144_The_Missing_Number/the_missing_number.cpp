#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<long long> numList;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	long long num;
	for( int i = 0; i < n; i++ ){
		cin>>num;
		if( num >= 0 ){
			numList.push_back(num);
		}
	}

	sort(numList.begin(), numList.end());


	int len = numList.size();
	if( len == 0 ){
		cout<<"1\n";
	}else if( len == 1 ){
		cout<<numList[0]+1<<'\n';
	}else{
		len--;
		bool flag = true;
		for( int i = 1; i < len; i++ ){
			if( numList[i] - numList[i-1] > 1 ){
				cout<<numList[i-1]+1<<'\n';
				flag = false;
				break;
			}
		}
		if( flag == true ){
			cout<<numList[len]+1<<'\n';
		}
	}



	return 0;
}

/*
** 2018 408 算法题
** 晴神模拟赛原题, 代码直接复制过去就AC了
** 万万没想到，这次 机试，难度远远低于往年 机试。甚至低于PAT
** 只要做过晴神的热身赛和模拟赛，机试就是 2道 签到题，半小时肯定能拿 20 + 25 = 45 分
** 第四题也是没有任何理解上的问题
** 也就是说，基础分是75分
** 
** 然而
** 然而
** 然而
** 我却放弃了机试，用9月份的54分PAT替代了成绩
** 从而失去了最后的，进入浙大的机会
** 骑着单车离开紫金港的那一刻
** 是我离浙大最近的时刻
** 
*/