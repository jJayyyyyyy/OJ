/*
https://www.nowcoder.com/test/question/done?tid=32350874&qid=221988#summary

招商银行信用卡中心2018秋招部分编程题汇总

这一套题目，开头难，中间简单，最后难，因此做题的时候，最好先把题目都看一遍，从容易的开始，而且每个题目可以先测试一下边界用例拿分，同时也可以检测一下思路是否正确

小招喵喜欢在数轴上跑来跑去，假设它现在站在点n处，它只会3种走法，分别是：
1.数轴上向前走一步，即n=n+1 
2.数轴上向后走一步,即n=n-1 
3.数轴上使劲跳跃到当前点的两倍，即n=2*n
现在小招喵在原点，即n=0，它想去点x处，快帮小招喵算算最快的走法需要多少步？


输入1： 3
输出1： 3


思路:
动态规划？递归？子问题？
https://www.nowcoder.com/questionTerminal/1177e9bd1b5e4e00bd39ca4ea9e4e216?f=discussion

dp[n] = 1 + min(dp[n + 1], dp[n - 1], 1 + dp[n / 2])

s1 = dp[i-1] + 1
s2 = dp[i/2] + 1,       i是偶数
s3 = dp[(i+1)/2] + 1,   i是奇数, 至于 (i+1), 是因为 i/2 * 2 此时到达的是 i-1 的位置

由于 x2 的跳跃在 n > 2 的时候肯定比 +1 的移动要快，

所以 dp[i] = min(s1, s2) 或者 min (s1, s3)

*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution{
public:
    int find_min(int n) {
        vector<int> dp(n + 1, 0x3fff0000);
        dp[0] = 0;
        dp[1] = 1;

        for ( int i = 2; i <= n; i++ ) {
            if ( i % 2 == 0 ) {
                dp[i] = 1 + min( dp[i - 1], dp[i / 2] );
            }
            else {
                dp[i] = 1 + min( dp[i - 1], 1 + dp[(i+1) / 2] );
            }
        }
        return dp[n];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if ( n <= 0 ) {
        n = -n;
    }
    
    Solution s;
    cout << s.find_min(n);
    return 0;
}

