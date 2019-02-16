#include <iostream>
#define MAXSIZE 10004
using namespace std;

int arr[MAXSIZE] = {0};
int max_sum_list[MAXSIZE] = {0};
int start_index[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len;
	cin >> len;

	bool all_negative = true;

	for( int i = 0; i < len; i++ )
	{
		cin >> arr[i];
		if( arr[i] >= 0 )
		{
			all_negative = false;
		}
	}

	if( all_negative == true )
	{
		cout << "0 " << arr[0] << ' ' << arr[len - 1] << '\n';
		return 0;
	}
	max_sum_list[0] = arr[0];

	// state transition equation
	for( int i = 1; i < len; i++ )
	{
		if( max_sum_list[i - 1] + arr[i] > arr[i] )
		{
			max_sum_list[i] = max_sum_list[i - 1] + arr[i];
			start_index[i] = start_index[i - 1];
		}
		else
		{
			max_sum_list[i] = arr[i];
			start_index[i] = i;
		}
	}

	int end_index = 0;
	int max_sum = max_sum_list[end_index];
	for( int i = 1; i < len; i++ )
	{
		if( max_sum_list[i] > max_sum )
		{
			max_sum = max_sum_list[i];
			end_index = i;
		}
	}

	int begin_index = start_index[end_index];
	int begin_value = arr[begin_index];
	int end_value = arr[end_index];

	cout<<max_sum<<' '<<begin_value<<' '<<end_value<<'\n';

	return 0;
}
