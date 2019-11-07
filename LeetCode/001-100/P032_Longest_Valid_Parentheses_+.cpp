/*
https://leetcode.com/problems/longest-valid-parentheses/description/?goto=old

括号匹配 同类题目 P032

输入：一串字符串 str
过程：字符串可能形成多段 符合规则的括号串（valid (well-formed) parentheses ），找出最长的那一段
输出：最长的那一段 【符合规则的括号串】 的长度

样例：

()      2
()()    4, 因为两段 () 都是符合规则的而且是连在一起的，所以可以合并成一段，且 长度为 4
(())    4, 外面的 () 包住了里面的 (), 还是一段符合规则的括号串
(())()  6,

重要样例
(()) )())(   4, 前面4个形成的串是符合规则的, 后面虽有一段(), 但是和前面没有连起来, 所以最长的还是前面的4


参考思路:
https://leetcode.com/problems/longest-valid-parentheses/solution/
动态规划， 详见下

*/

#include <iostream>
#include <vector>
using namespace std;


// // io加速
// static const auto io_speed_up = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// } ();

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };


class Solution {
public:
    int longestValidParentheses(string str) {
        // dp 记录以当前括号为结尾, 能够形成的 符合规则的 连续的 括号串 的最大长度
        // dp 初始化为 0, 即初始默认无法形成 括号串
        int len = str.size();
        vector<int> dp(len, 0);
        // ans 则是要找出全局最长的那一段的长度
        int ans = 0;

        for ( int i = 1; i < len; i++ ) {
            char ch = str[i];
            if ( ch == ')' ) {
                if ( str[i - 1] == '(' ) {
                    // 此时 str[i] == )
                    // 而且 str[i-1] 是 (
                    // 因此可以形成最短括号串
                    if ( i >= 2 ) {
                        // s[i-1] 和 s[i] 形成括号串, 并且尝试连接到前面的括号串
                        // 如果 dp[i - 2] == 0 说明不能和前面形成连续的括号串
                        // 如果 dp[i - 2] > 0 说明可以和前面形成连续的括号串
                        dp[i] = dp[i - 2] + 2;
                    }
                    else {
                        // s[0] 是 (, s[1] 是 ), 可以形成最短括号串
                        // 相当于 dp[-1] = 0
                        // dp[i] = 2;
                    }
                }
                else {
                    // 此时 str[i] == )
                    // dp[i-1] 是 str[i] 之前的最大连续合规长度
                    int max_cont_valid_len = dp[i - 1];

                    // 当前位置 i 减去 max_cont_valid_len 就是上一处不符合规则的位置
                    int ix = i - max_cont_valid_len - 1;
                    if ( ix >= 0 && str[ix] == '(' ) {
                        // 此时 str[ix] 处的 ( 可以和 str[i] 处的 ) 形成一对括号
                        
                        if ( ix >= 1 ) {
                            dp[i] = dp[ix - 1] + max_cont_valid_len + 2;
                        }
                        else {
                            // ix - 1 == -1
                            // dp[-1] == 0
                            dp[i] = 0 + max_cont_valid_len + 2;
                        }
                    }
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }

    // 也可以在最前面加上一个 dummyhead #, 这样可以省去几步 >= 0 的判断
    int longestValidParentheses_dummyhead(string str) {
        // dp 记录以当前括号为结尾, 能够形成的 符合规则的 连续的 括号串 的最大长度
        // dp 初始化为 0, 即初始默认无法形成 括号串
        string dummyhead = "#";
        str = dummyhead + str;
        int len = str.size();
        vector<int> dp(len, 0);
        // ans 则是要找出全局最长的那一段的长度
        int ans = 0;

        for ( int i = 2; i < len; i++ ) {
            char ch = str[i];
            if ( ch == ')' ) {
                if ( str[i - 1] == '(' ) {
                    dp[i] = dp[i - 2] + 2;
                }
                else {
                    int max_cont_valid_len = dp[i - 1];
                    int ix = i - max_cont_valid_len - 1;
                    if ( ix >= 0 && str[ix] == '(' ) {
                        dp[i] = dp[ix - 1] + max_cont_valid_len + 2;
                    }
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    
    // test cases
    // ( ()     --- 2
    cout << s.longestValidParentheses("(()") << '\n';
    // () ()    --- 4
    cout << s.longestValidParentheses("()()") << '\n';
    // (())     --- 4
    cout << s.longestValidParentheses("(())") << '\n';
    // ( (())   --- 4
    cout << s.longestValidParentheses("((())") << '\n';
    // () (())  --- 6
    cout << s.longestValidParentheses("()(())") << '\n';
    // () (()())    --- 6
    cout << s.longestValidParentheses("()(()())") << '\n';
    // (()) )())(   --- 4
    cout << s.longestValidParentheses("(()))())(") << '\n';
    return 0;
}
