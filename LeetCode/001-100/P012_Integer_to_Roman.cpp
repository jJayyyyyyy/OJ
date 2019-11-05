/*
https://leetcode.com/problems/integer-to-roman/description/?goto=old

罗马数字与阿拉伯数字的转换 同类题目 P012, P013

输入：阿拉伯数字 num
过程：转换为罗马数字 ans
输出：罗马数字 ans

思路:
各种if
https://leetcode.com/problems/integer-to-roman/discuss/550038/100-Faster-and-100-Less-Memory-:-Simple-C++-Solution

进位会发生在 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
// 不得不说这罗马人的脑回路很奇怪

不断对 num 减去当前的最大进位, 如果减去进位后 num >= 0 则添加当前的进位符号

分步思路见 Solution_part, 整合思路见 Solution

*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// } ();

class Solution {
public:
    string intToRoman(int num) {
        vector<int> carry_list = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> carry_symbol_list = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int len = carry_list.size();
        int i = 0;
        string ans = "";

        while ( num > 0 && i < len ) {
            int carry = carry_list[i];
            string carry_symbol = carry_symbol_list[i];
            if ( num - carry >= 0 ) {
                ans.append(carry_symbol);
                num -= carry;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};

class Solution_part {
public:
    string intToRoman(int num) {
        // vector<char> roman;
        string ans;
        while ( num >= 1000 ) {
            // roman.push_back('M');
            ans.append("M");
            num -= 1000;
        }

        // 0 <= num < 1000
        if ( num >= 900 ) {
            // 900 <= num < 1000
            ans.append("CM");
            num -= 900;
            // 0 <= num < 100
        }
        
        // 0 <= num < 900
        if ( num >= 500 ) {
            // 500 <= num < 900
            ans.append("D");
            num -= 500;
            // 0 <= num < 400
        }

        // 0 <= num < 500
        if ( num >= 400 ) {
            // 400 <= num < 500
            ans.append("CD");
            num -= 400;
            // 0 <= num < 100
        }

        // 0 <= num < 400
        while ( num >= 100 ) {
            // 100 <= num < 400
            ans.append("C");
            num -= 100;
            // 0 <= num < 100
        }
        
        // 0 <= num < 100
        if ( num >= 90 ) {
            // 90 <= num < 100
            ans.append("XC");
            num -= 90;
            // 0 <= num < 10;
        }

        // 0 <= num < 90
        if ( num >= 50 ) {
            // 50 <= num < 90
            ans.append("L");
            num -= 50;
            // 0 <= num < 40
        }

        // 0 <= num < 50
        if ( num >= 40 ) {
            // 40 <= num < 50
            ans.append("XL");
            num -= 40;
            // 0 <= num < 10
        }

        // 0 <= num < 40
        while ( num >= 10 ) {
            // 10 <= num < 40
            ans.append("X");
            num -= 10;
            // 0 <= num < 10
        }


        // 0 <= num < 10
        if ( num >= 9 ) {
            // 9 <= num < 10
            ans.append("IX");
            num -= 9;
            // 0 <= num < 1;
        }

        // 0 <= num < 9
        if ( num >= 5 ) {
            // 5 <= num < 9
            ans.append("V");
            num -= 5;
            // 0 <= num < 4
        }

        // 0 <= num < 5
        if ( num >= 4 ) {
            // 4 <= num < 5
            ans.append("IV");
            num -= 4;
            // 0 <= num < 1
        }

        // 0 <= num < 4
        while ( num >= 1 ) {
            // 1 <= num < 4
            ans.append("I");
            num -= 1;
            // 0 <= num < 1
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.intToRoman(3) << ' ' << "III" << '\n';
    cout << s.intToRoman(4) << ' ' << "IV" << '\n';
    cout << s.intToRoman(9) << ' ' << "IX" << '\n';
    cout << s.intToRoman(58) << ' ' << "LVIII" << '\n';
    cout << s.intToRoman(1994) << ' ' << "MCMXCIV" << '\n';
    return 0;
}
