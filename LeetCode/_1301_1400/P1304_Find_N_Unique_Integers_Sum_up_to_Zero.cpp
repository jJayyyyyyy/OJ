/*
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?goto=old

输入： n
输出： 数组 ans
要求：
1. ans.size() == n
2. accumulate(ans.begin(), ans.end(), 0) = 0

例
输入： n = 3
输出： ans = [0, -1, 1]


同类题目 P1304

参考思路1
分类讨论
若 n 为奇数， 则先 push_back 一个 0， 然后依次添加 1, 2, ... , n/2; -1, -2, ..., -n/2
若 n 为偶数， 则依次添加 1, 2, ... , n/2; -1, -2, ..., -n/2

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if ( n % 2 == 1 ) {
            ans.push_back(0);
        }
        int half_n = n / 2;
        for ( int i = 1; i <= half_n; i++ ) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.sumZero(5);
    s.sumZero(3);
    s.sumZero(4);
    return 0;
}