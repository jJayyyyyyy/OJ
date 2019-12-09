/*
https://www.nowcoder.com/test/question/6e3ff5d892c342ae8f367355b66bab55?pid=11828403&tid=32350874

招商银行信用卡中心2018秋招部分编程题汇总

给出一个非空的字符串 str，判断这个字符串是否是由它的一个子串进行多次首尾拼接构成的。
例如，"abcabcabc"满足条件，因为它是由"abc"首尾拼接而成的，而"abcab"则不满足条件。


输入1： abcabc
输出1： abc

输入2： abcab
输出2： false


思路:
设 len = str.size();
设 step = substr.size();


1. 先分析边界情况 ( len <= 3 ) 快速拿分

2. 通用情况

如果 substr 满足要求, 那么 step <= len / 2, 且
str[0] == str[step] == str[2 * step] == ...
str[1] == str[step + 1] == str[2 * step + 1] == ...
...
str[step - 1] == str[2 * step - 1] == str[3 * step] == ...

*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int len = str.size();
    if ( len <= 1 ) {
        cout << str;
        return 0;
    }

    if ( len == 2 ) {
        if ( str[0] == str[1] ) {
            cout << str[0];
        }
        else {
            cout << "false";
        }
        return 0;
    }

    if ( len == 3 ) {
        if ( str[0] == str[1] == str[2] ) {
            cout << str[0];
        }
        else {
            cout << "false";
        }
    }

    int div = 1;
    int step = len;
    while ( step >= 1 ) {
        div++;
        step = len / div;
        if ( step == 0 ) {
            break;
        }
        if ( len % step == 0 ) {
            bool has_substr = true;
            int i = 0;
            for ( ; i < step; i++ ) {
                int j = i + step;
                for ( ; j < len; j += step ) {
                    if ( str[i] != str[j] ) {
                        has_substr = false;
                        break;
                    }
                }
                if ( has_substr == false ) {
                    break;
                }
            }
            if ( has_substr == true && i == step ) {
                cout << str.substr(0, i);
                return 0;
            }
        }
    }
    cout << "false";

    return 0;
}

