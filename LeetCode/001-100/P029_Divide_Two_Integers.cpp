/*
https://leetcode.com/problems/divide-two-integers/description/?goto=old

同类题目 P029

主要考虑边界情况, dividend == INT_MIN || divisor == INT_MIN

此外，可以优化的地方就是减少减法的次数，可以通过增加步长来实现
*/

#include <iostream>
#include <vector>
using namespace std;

static const auto io_speed_up = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if ( divisor == 0 ) {
            return INT_MAX;
        }

        /*    -2147483648 / -1, overflow    */
        if ( dividend == INT_MIN && divisor == -1 ) {
            return INT_MAX;
        }
        /*    -2147483648 / 1, not overflow    */
        if ( dividend == INT_MIN && divisor == 1 ) {
            return INT_MIN;
        }

        int res = 0;
        /*    abs(-2147483648), overflow    */
        if ( dividend == INT_MIN ) {
            if ( divisor == INT_MIN ) {
                return 1;
            }

            if ( divisor > 0 ) {
                while ( dividend + divisor <= 0 ) {
                    dividend += divisor;
                    res--;
                }
                return res;
            }
            if ( divisor < 0 ) {
                while ( dividend - divisor <= 0 ) {
                    dividend -= divisor;
                    res++;
                }
                return res;
            }
        }

        else if ( divisor == INT_MIN ) {
            return 0;
        }

        bool pos = true;
        if ( (dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0) ) {
            pos = false;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);

        // 此处主要优化步长，即让每一步减法的跨度尽可能大
        if ( divisor == 1 ) {
            res = dividend;
        }
        else if ( divisor == 2 ) {
            res = dividend >> 1;
        }
        else if ( divisor == 4 ) {
            res = dividend >> 2;
        }
        else if ( divisor == 8 ) {
            res = dividend >> 3;
        }
        else if ( divisor < (2<<10) ) {
            // 增加每一步的步长
            for ( int i = 20; i >= 0; i-- ) {
                int tmp_div = divisor << i;
                int tmp_add = 1 << i;
                while ( dividend - tmp_div >= 0 ) {
                    dividend -= tmp_div;
                    res += tmp_add;
                }
            }
        }
        else {
            while ( dividend - divisor >= 0 ) {
                dividend -= divisor;
                res+=1;
            }
        }

        if ( pos == false ) {
            res = -res;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.divide(6, 2) << '\n';
    cout << s.divide(10, 3) << '\n';
    cout << s.divide(7, -3) << '\n';
    cout << s.divide(INT_MAX, -1) << '\n';
    cout << s.divide(INT_MAX, 1) << '\n';

    return 0;
}