#include<iostream>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;

int N, M;
vector<int> v;
void solution(){
	cin >> N;
	long int temp; int num;
	v.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &temp);
		num = min(temp, (long int)INT_MAX);
		v[i] = num;
	}
	v[N] = INT_MAX;
	cin >> M;
	int j = 0, cnt = 0;
	int i = 0;
	for (i = 0; i < M; i++)
	{
		scanf("%ld", &temp);
		num = min(temp, (long int)INT_MAX);
		while (num >= v[j] && j < N)
		{
			j++;
			cnt++;
			if (cnt == (M + N + 1) / 2)
			{
				cout << v[j - 1];
				return;
			}
		}
		cnt++;
		if (cnt == (M + N + 1) / 2)
		{
			cout << temp;
			return;
		}
	}
	while (cnt<(M + N + 1) / 2)
	{
		j++;
		cnt++;
	}
	cout << v[j - 1];
	return;
}

int main(){
	solution();
	return 0;
}