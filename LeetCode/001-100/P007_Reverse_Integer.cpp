/*
https://leetcode.com/problems/reverse-integer/description/
给定一个整数，倒序输出。若超出32位有符号整数的范围，则返回0

限定条件:
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
因此程序中不能使用 long long 或者 unsigned 之类的来绕过整数溢出的条件限制

思路:
对10取余 ---> x10 ---> 累加
例如: 输入 x = 123

ans_after = 0
ans_before = 0
while x != 0:
    x = 123
    remainder = x % 10 = 3
    x = x / 10
    if  终止条件(ans_before 会导致 ans_after 溢出):
        ans_after = 0
        break
    else:
        ans_after = ans_before * 10 + remainder
        ans_before = ans_after

其中的关键在于 终止条件(ans_before 会导致 ans_after 溢出), 题目要求
    1). INT_MIN <= ans_after <= INT_MAX 
也就是要求
    2). INT_MIN <= ans_before * 10 + remainder <= INT_MAX
由于 INT_MIN、INT_MAX ± remainder 很可能导致溢出, 所以不能直接将 remainder 移项
而是先对两边各自作除法 / 10, 再移项, 即
    3). (INT_MIN / 10) - (remainder / 10) <= ans_before <= (INT_MAX / 10) - (remainder / 10)
由于 remainder / 10 在整除的时候得到的结果是 0
因此 3). 可以转为
    4). (INT_MIN / 10) <= ans_before <= (INT_MAX / 10)

如果 ans_before 超出了 4). 的范围, 那么 ans_after 肯定不满足题目要求
而当 ans_before 在 4). 的范围中时, 也需要分类讨论, 考虑边界是否会溢出, 因为 remainder / 10 = 0 丢失了部分精度

a). 如果 4). 的等号不成立, 即
        5). (INT_MIN / 10) < ans_before < (INT_MAX / 10)
    由于 INT_MIN = -2147483648, INT_MAX = 2147483647
    那么
        -214748364 < ans_before < 214748364
    即
        -214748363 <= ans_before <= 214748363
    即
        -2147483630 + remainder <= ans_before * 10 + remainder <= 2147483630 + remainder
    由于 remainder 是个位数, 即 -10 < remainder < 10, 因此
        左边 = -2147483630 + remainder > -2147483630 + (-10) = -2147483640 > -2147483648 = INT_MIN
        右边 = 2147483630 + remainder < 2147483630 + 10 = 2147483640 < 2147483647 = INT_MAX
    因此
        INT_MIN < -2147483640 < ans_before * 10 + remainder < 2147483640 < INT_MAX
    即
        INT_MIN < -2147483640 < ans_after < 2147483640 < INT_MAX
    即
        INT_MIN < ans_after < INT_MAX
    符合题目要求, 不会溢出 32 位有符号整数范围

b). 如果 4). 的等号成立, 即
        (INT_MIN / 10) = ans_before = (INT_MAX / 10)
    则可分为以下两种情况
        6). ans_before = (INT_MIN / 10)
        7). ans_before = (INT_MAX / 10)
    对于 6). 若再满足下式, 则 ans_after 符合题意
        INT_MIN <= ans_after = ans_before * 10 + remainder
    由此可得
        INT_MIN - ans_before * 10 <= remainder
    即
        INT_MIN - (INT_MIN / 10) * 10 = -8 <= remainder
    即要求
        ans_before = (INT_MIN / 10) 且 remainder >= -8
    因此, 若 
        remainder < -8
    则会导致 ans_after 超出 INT_MIN 的范围, 导致下溢
    
    同理, 对于 7). 若再满足下式, 则 ans_after 符合题意
        ans_after = ans_before * 10 + remainder <= INT_MAX
    由此可得
        ans_before = (INT_MAX / 10) 且 remainder <= 7 时
    可使 ans_after 满足题意, 而当 remainder > 7 时, 会 ans_after 超出 INT_MAX 范围, 导致上溢

综上可得,  终止条件(ans_before 会导致 ans_after 溢出) (即使 ans_after 不满足题意的条件) 为
        A). ans_before > INT_MAX / 10
    或  B). ans_before < INT_MIN / 10
    或  C). ans_before == INT_MAX 且 remainder > 7
    或  D). ans_before == INT_MIN 且 remainder < -8
*/

#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        int remainder = 0, ans = 0, ans_before = 0, ans_after = 0;
        int INT_MAX_DIV_10 = INT_MAX / 10;                        // 2147483647
        int INT_MAX_REMAINDER = INT_MAX - INT_MAX_DIV_10 * 10;    // 7
        int INT_MIN_DIV_10 = INT_MIN / 10;                        // -2147483648
        int INT_MIN_REMAINDER = INT_MIN - INT_MIN_DIV_10 * 10;    // -8
        while ( x != 0 ) {
            remainder = x % 10;
            if (   (ans_before > INT_MAX_DIV_10) 
                || (ans_before < INT_MIN_DIV_10)
                || (ans_before == INT_MAX_DIV_10 && remainder > INT_MAX_REMAINDER)
                || (ans_before == INT_MIN_DIV_10 && remainder < INT_MIN_REMAINDER) ) {
                ans = 0;
                break;
            }
            else {
                ans_after = ans_before * 10 + remainder;
                ans_before = ans_after;
                ans = ans_after;
                x /= 10;
            }
        }
        return ans;
    }

    int reverseSimplify(int x) {
        int remainder = 0;
        int ans = 0;
        while ( x != 0 ) {
            remainder = x % 10;
            if ( ans > INT_MAX / 10 || (ans == INT_MAX / 10 && remainder > 7) ) {
                return 0;
            }
            if ( ans < INT_MIN / 10 || (ans == INT_MIN / 10 && remainder < -8) ) {
                return 0;
            }
            ans = ans * 10 + remainder;
            x /= 10;
        }
        return ans;
    }

    int reverseBF(int x) {
        if ( x == 0 ) {
            return 0;
        }

        std::string s = std::to_string(x);
        if( s[0] == '-' ){
            std::reverse(s.begin() + 1, s.end());
        }else{
            std::reverse(s.begin(), s.end());
        }
        // 不允许使用 long long
        long long res = std::stoll(s);
        
        if ( res < INT_MIN || res > INT_MAX ) {
            return 0;
        }
        else {
            return (int) res;
        }
    }
};


int main(){
    Solution s;
    std::cout << s.reverse(123);
    std::cout << s.reverse(-1563847412);
    std::cout << s.reverse(INT_MIN);
    std::cout << s.reverse(INT_MAX);
    return 0;
}
