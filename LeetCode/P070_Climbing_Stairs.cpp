/*
 * https://leetcode.com/problems/climbing-stairs/description/
 * 爬楼梯, fibonacci序列
 * 同类题目 
 * 一次只能爬 1 级或者 2 级楼梯, 如果一共有 n 级楼梯, 那么一共有多少种爬法?
 * 思路: f(n) = f(n-1) + f(n-2), 第 n 级楼梯只能通过第 n-1 级楼梯一次性向上走一步, 或者 从第 n-2 级楼梯一次性向上走两步到达
 * 由此可以想到 fibonacci 序列. 实际上, f(n) == fibonacci(n) 
 *
*/

// #include <iostream>
// using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	int climbStairs(int n) {
		if( n == 1 ){
			return 1;
		}else if( n == 2 ){
			return 2;
		}else{
			int a = 1;
			int b = 2;
			int c;
			for( int i = 3; i <= n; i++ ){
				c = a + b;
				a = b;
				b = c;
			}
			return c;
		}
	}
};
// 时间复杂度: O(n)
// 空间复杂度: O(1)
// 分析: https://leetcode.com/problems/climbing-stairs/solution/


// int main(){
// 	Solution s;

// 	cout<<s.climbStairs(1)<<'\n';	// 1
// 	cout<<s.climbStairs(2)<<'\n';	// 2
// 	cout<<s.climbStairs(3)<<'\n';	// 3
// 	cout<<s.climbStairs(4)<<'\n';	// 5
// 	cout<<s.climbStairs(5)<<'\n';	// 8
// 	return 0;
// }
