/*
https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?goto=old

输入： n
输出： 数组 res
要求：
1. res.size() == 2
2. res[0] + res[1] == n
3. No "0" in res[0] or res[1]
4. It is guarateed that there's at least one valid solution.

例
输入： n = 2
输出： res = [1, 1]


同类题目 P1317

参考思路
As it is described in the problem, we have to find a pair of non-zero A and B to make a list.

1. Firstly, it is a good idea to iterate A from 1 to n, then let B = n - A
2. Secondly, it would be helpful to design a function called [containsZero] to check if there is "0" in a given number.

Combining these two steps, the problem can be solved.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2, 0);
        if ( n < 2 ) {
            return res;
        }

        int a = 1, b = n - a;
        for ( ; a < n; a++ ) {
            b = n - a;
            if ( !containsZero(a) && !containsZero(b) ) {
                res[0] = a;
                res[1] = b;
                break;
            }
        }
        return res;
    }

    bool containsZero(int num) {
        string str_num = to_string(num);
        return str_num.find('0') != string::npos;
    }
};

int main() {
    Solution s;
    vector<int> res(2, 0);

    res = s.getNoZeroIntegers(2);
    cout << res[0] << ' ' << res[1] << '\n';

    res = s.getNoZeroIntegers(11);
    cout << res[0] << ' ' << res[1] << '\n';

    res = s.getNoZeroIntegers(10000);
    cout << res[0] << ' ' << res[1] << '\n';

    res = s.getNoZeroIntegers(69);
    cout << res[0] << ' ' << res[1] << '\n';

    res = s.getNoZeroIntegers(1010);
    cout << res[0] << ' ' << res[1] << '\n';

    return 0;
}