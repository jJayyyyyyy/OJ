/*
https://leetcode.com/problems/available-captures-for-rook/
给定国际象棋的棋盘, 统计在一步棋中, 车(Rook)最多可以攻击多少个兵(pawn)
同类题目 P999
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution
{
public:
	int numRookCaptures(vector< vector<char> > & board)
	{
		int ri, rj;
		for( int i = 0; i < 8; i++ )
		{
			for( int j = 0; j < 8; j++ )
			{
				if( board[i][j] == 'R' )
				{
					ri = i;
					rj = j;
					goto NEXT;
				}
			}
		}
	NEXT:
		int cnt = 0;
		for( int i = ri - 1; i >= 0; i-- )
		{
			char cell = board[i][rj];
			if( cell == '.' )
			{
				continue;
			}
			else if( cell == 'p' )
			{
				cnt++;
				break;
			}
			else
			{
				break;
			}
		}

		for( int i = ri + 1; i < 8; i++ )
		{
			char cell = board[i][rj];
			if( cell == '.' )
			{
				continue;
			}
			else if( cell == 'p' )
			{
				cnt++;
				break;
			}
			else
			{
				break;
			}
		}

		for( int j = rj - 1; j >= 0; j-- )
		{
			char cell = board[ri][j];
			if( cell == '.' )
			{
				continue;
			}
			else if( cell == 'p' )
			{
				cnt++;
				break;
			}
			else
			{
				break;
			}
		}

		for( int j = rj + 1; j < 8; j++ )
		{
			char cell = board[ri][j];
			if( cell == '.' )
			{
				continue;
			}
			else if( cell == 'p' )
			{
				cnt++;
				break;
			}
			else
			{
				break;
			}
		}

		return cnt;
	}
};