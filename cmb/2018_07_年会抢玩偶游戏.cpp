/*
https://www.nowcoder.com/questionTerminal/cfb7734a7c844350895f2e269a38195d?f=discussion

招商银行信用卡中心2018秋招开发方向笔试题

某公司年会上，组织人员安排了一个小游戏来调节气氛。游戏规则如下：

N个人参与游戏，站成一排来抢工作人抛来的M个小玩偶。为了增加游戏的趣味和难度，规则规定，参与游戏的人抢到的礼物不能比左右两边的人多两个或以上，否则会受到一定的惩罚。游戏结束时拥有玩偶最多的人将获得一份大奖。
假设大家都想赢得这份大奖，请问站在第K个位置的小招在赢得游戏时，最多能拥有几个玩偶？

输入1： 1 1 0
输出1： 0

输入2： 1 3 1
输出2： 3

思路:
先解决边界情况!!!


然后再找规律完成剩下用例

        o
      o o o
  o o o o o o o o o o o o o o o o

m + 1 时 , 先要平铺

        o
      o o o o
  o o o o o o o o o o o o o o o o

m 再 + 1 时

        o o
      o o o o
  o o o o o o o o o o o o o o o o

m 再 + 1 时

        o o
    o o o o o
  o o o o o o o o o o o o o o o o

m 再 + 1 时

      o o o
    o o o o o
  o o o o o o o o o o o o o o o o

m 再 + 1 时

        o
      o o o
    o o o o o
  o o o o o o o o o o o o o o o o


最优解类似于求杨辉三角的高
                   +
        o          |
      o o o        |
    o o o o o      y = height
  o o o o o o o    |
o o o o o o o o o  |
                   +
{------ x ------}

mmax = 1 + 3 + 5 + ... + x = y^2,   x = y * 2 - 1, y = height

height = sqrt(mmax)

x = y * 2 - 1

n >= x, ans = y

n < x, ???

*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    if ( n <= 0 || m <= 0 ) {
        cout << 0;
        return 0;
    }

    if ( k < 1 || k > n ) {
        cout << 0;
        return 0;
    }

    if ( n == 1 ) {
        cout << m;
        return 0;
    }

    // n=4, m=2 ---> 1
    // n=4, m=3 ---> 1
    // n=4, m=4 ---> 1
    // n=4, m=5 ---> 2
    // n >= m 时, 最多能抢1个，否则会被惩罚
    if ( n >= m ) {
        cout << 1;
        return 0;
    }

    int height = sqrt(m);
    if ( n > height * 2 - 1 ) {
        cout << height;
        return 0;
    }
    // 至此能够通过所有用例

    if ( n < height * 2 - 1 ) {
        // ???
    }


    return 0;
}
