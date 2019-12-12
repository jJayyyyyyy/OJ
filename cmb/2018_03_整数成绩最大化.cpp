/*
https://www.nowcoder.com/test/question/done?tid=32350874&qid=221986#summary

招商银行信用卡中心2018秋招部分编程题汇总

给出一个整数n，将n分解为至少两个整数之和，使得这些整数的乘积最大化，输出能够获得的最大的乘积。
例如：
2=1+1，输出1；
10=3+3+4，输出36。


输入1： 10
输出1： 36



剑指offer原题 --- 剪绳子
https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&tqId=33257&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

思路:
尽量把 n 剪成长度为 3 的片段

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int cutRope(int number) {
        if ( number <= 1 ) {
            return 0;
        }
        else if ( number == 2 ) {
            return 1;
        }
        else if ( number == 3 ) {
            return 2;
        }
        else if ( number == 4 ) {
            return 4;
        }
        else {
            int ans = 1;
            while ( number >= 3 ) {
                ans *= 3;
                number -= 3;
            }
            if ( number > 0 ) {
                ans *= number;
            }
            return ans;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Solution s;
    cout << s.cutRope(n);
    return 0;
}

