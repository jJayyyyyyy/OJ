#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len;
	cin >> len;
	vector<int> req_list(len + 1);
	req_list[0] = 0;
	for( int i = 1; i <= len; i++ )
	{
		cin >> req_list[i];
	}

	int sum = 0;
	for( int i = 1; i <= len; i++ )
	{
		int gap = req_list[i] - req_list[i - 1];
		if( gap > 0 )
		{
			sum += gap * 6 + 5;
		}
		else
		{
			sum += -gap * 4 + 5;
		}
	}
	cout << sum << '\n';

	return 0;
}
