/*
https://www.nowcoder.com/test/question/done?tid=32350874&qid=221987#summary

招商银行信用卡中心2018秋招部分编程题汇总

这一套题目，开头难，中间简单，最后难，因此做题的时候，最好先把题目都看一遍，从容易的开始，而且每个题目可以先测试一下边界用例拿分，同时也可以检测一下思路是否正确

从非负整数序列 0, 1, 2, ..., n 中给出包含其中n个数的子序列, 找出不在该子序列中的那个数

输入1： 3 3 0 1
输出1： 2

说明：
输入中的第一个数 3 是 n， 即序列的最大值，即完整序列有 n+1 个数
而 n 后面输入的是 n 个数,

思路:
第一反应是 bitmap, 但是 n 太大时会使得整个bool vector长度较大
第二思路是套用求和公式 sum = (1 + n) * n / 2, 减去输入的和, 就是遗漏的那个数, 此时需要考虑可能存在的溢出问题
*/

#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if ( n <= 0 ) {
        cout << 0;
    }
    else {
        long long sum1 = (1 + n) * n / 2;
        long long sum2 = 0;
        long long num;
        for ( int i = 0; i < n; i++ ) {
            cin >> num;
            sum2 += num;
        }
        cout << sum1 - sum2;
    }
    return 0;
}

