/*
https://www.nowcoder.com/questionTerminal/3690a506d0374981863ca649d97b81b7?f=discussion

招商银行信用卡中心2018秋招部分编程题汇总

给出一个正整数n，请给出所有的包含n个'('和n个')'的字符串，使得'('和')'可以完全匹配。
例如：
'(())()'，'()()()' 都是合法的；
'())()('是不合法的。
请按照__字典序__给出所有合法的字符串。


输入1： 2
输出1： (()),()()

输入2： 3
输出2： ((())),(()()),(())(),()(()),()()()


思路:
由于题目要求字典序，因此我们可以
1. 先尽量填充左括号 (    , 填充数量为 nleft
2. 然后填充对应数量的右括号 )    , 填充数量为 nright
3. 把 nright 个 右括号) 退出来, 再退出一个 左括号(, 并且替换为右括号
4. 回到 1

01
((( )))


02
((( )))
(((
(() (
(() ()
(() ()) --- (()())


03
(() ())
(() (
(() )
(() ) (
(() ) () --- (())()


04
(())()
(() ) ()
(
()
() ((
() (()) --- ()(())


05
() (())
() ()
() ()() --- ()()()
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> ans;
public:
    void print(){
        int len = ans.size();
        if ( len >= 1 ) {
            cout << ans[0];
            for ( int i = 1; i < len; i++ ) {
                cout << ',' << ans[i];
            }
        }
    }

    void process(string & str, int nleft, int nright, int n) {
        if ( nleft < n ) {
            str.push_back('(');
            // add_left()
            process(str, nleft + 1, nright, n);
            str.pop_back();
        }
        // 此时进入 left == n 以后的递归

        // 要保证 左括号数量 > 右括号数量
        if ( nleft > nright ) {
            str.push_back(')');
            // add_right()
            process(str, nleft, nright + 1, n);
            str.pop_back();
        }

        // left == n == right == n
        if ( nleft == n && nright == n ) {
            ans.push_back(str);
            return;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Solution s;
    string str = "";
    int left = 0, right = 0;
    s.process(str, left, right, n);
    s.print();
    return 0;
}

