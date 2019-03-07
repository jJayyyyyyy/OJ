/*
https://leetcode.com/problems/unique-binary-search-trees/description/
求 [1, n] 组成的 BST 有多少种树的形态

参考 1: https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
参考 2: https://leetcode.com/problems/unique-binary-search-trees/discuss/31671/A-very-simple-and-straight-ans-based-on-MathCatalan-Number-O(N)-timesO(1)space
参考 3: https://blog.csdn.net/adminabcd/article/details/46672759

其实与 BST 没啥关系
只是求 n 个结点的二叉树有多少种形态
即 Catalan 数
f(n) = (2n)! / [ n! · (n+1)!]
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		//  不能这么做, n 很大的时候会溢出
		/*
		unsigned long long up = 1, down = 1;
		for( int i = 1; i <= n; i++ )
		{
			down *= i;
		}
		for( int i = n + 2; i <= 2 * n; i++ )
		{
			up *= i;
		}
		unsigned long long ans = up / down;
		*/

		unsigned long long ans = 1;
		int up_bound = 2 * n;
		for( int i = n + 1; i <= up_bound; i++ )
		{
			ans = ans * i / (i - n);
		}
		ans /= (n + 1)
		return ans;
	}
};
