#include <iostream>
#include <vector>
using namespace std;

void print_line(int width, char ch)
{
	for( int i = 0; i < width; i++ )
	{
		cout << ch;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ttl_cnt;
	char symbol;

	cin >> ttl_cnt >> symbol;

	if( ttl_cnt <= 1 )
	{
		cout << symbol << "\n0\n";
	}
	else
	{
		vector<int> width_list;
		width_list.push_back(1);
		ttl_cnt -= 1;		// cnt 表示目前还剩下多少个星星
		int width = 3;		// width 表示当前这一行有多少个星星
		while( true )
		{
			ttl_cnt -= width * 2;	// 上下对称, 因此总数 ttl_cnt -= width * 2
			if( ttl_cnt >= 0 )
			{
				width_list.push_back(width);
				width += 2;
			}
			else
			{
				ttl_cnt += width * 2;
				break;
			}
		}

		int len = width_list.size();
		int max_width = width_list[len - 1];
		for( int i = len - 1; i >= 0; i-- )
		{
			width = width_list[i];
			int space_width = ( max_width  - width ) / 2;
			print_line( space_width, ' ' );
			print_line( width, symbol );
			cout << '\n';
		}

		for( int i = 1; i < len; i++ )
		{
			int width = width_list[i];
			int space_width = ( max_width  - width ) / 2;
			print_line( space_width, ' ' );
			print_line( width, symbol );
			cout << '\n';
		}
		cout << ttl_cnt << '\n';
	}
	return 0;
}

/*
1 7 17 31 49 71 97 127 161 199 241 287 337 391 449 511 577 647 721 799 881 967
*/
