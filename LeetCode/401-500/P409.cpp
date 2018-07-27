/*
https://leetcode.com/problems/sum-of-left-leaves/description/
找到所有的左叶结点, 进行值的求和
同类题目 P412

*/

/*
1. charCnt[]

2. even -> ans+=

3. odd, -> 坑。。可以只用一部分

   如 ccc 可以用 2个c，而不是【要么用，要么不用】
   
   
*/

class Solution {
public:
	int longestPalindrome(string s) {
		int charCnt[128] = {0};

		for( char ch : s ){
			charCnt[ch]++;
		}

		int ans = 0;
		bool hasOdd = false;
		for( int i = 'A'; i <= 'z'; i++ ){
			int cnt = charCnt[i];
			if( cnt % 2 == 0 ){
				ans += cnt;
			}else{
				hasOdd = true;
				ans += cnt - 1;
			}
		}

		if( hasOdd ){
			ans++;
		}
		return ans;
	}
};