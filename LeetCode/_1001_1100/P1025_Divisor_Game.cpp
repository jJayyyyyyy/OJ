/*
https://leetcode.com/problems/divisor-game/description/?goto=old

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.


同类题目 P1025
参考思路
https://leetcode.com/problems/divisor-game/discuss/274606/JavaC++Python-return-N-2-0

https://leetcode.com/problems/divisor-game/discuss/274566/just-return-N-2-0-(proof)

Alice 先手，证明：N为偶数的时候，Alice 可以保证必胜

证1:
1. N = 2时，选 x=1，此时 N = 1，Bob没法选择，则 Alice 必赢
2. N = 4时，选 x=1，此时 N = 3，则 Bob 只能选 x=1，回到 N = 2 的情况
3. 由于 N = 2n 时，选 x=1，会使得 N = 2k+1 变成奇数，没有偶数因子，因此 Bob 只能选 x=奇数，这样使得 N = 2i 又变成偶数。由于我们是从小到大推论的，因此 N = 2n 前面的偶数肯定是能使 Alice 必胜的，

Alice 先手，证明：N为奇数的时候，只要Bob每次都选取最优解，Alice必输
证2：
因为 N 为奇数，所以 Alice 只能选奇数因子x，这样会使得 N 变成偶数
这样原问题就转化成了 Bob先手，证明N为偶数的时候，Bob 可以保证必胜
这点已经在证1中证明过了

*/

#include <iostream>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	bool divisorGame(int N) {
		return N % 2 == 0;
	}
};