/*
https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?goto=old

输入一组数字 nums, 如 [12,345,2,7896], 其中 12, 7896 的位数分别是 2 和 4，是偶数，其他数字的位数都是奇数。
求 nums 中位数为偶数的数字的个数

同类题目 P1295

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int> & nums) {
        int cnt = 0;
        for ( const int & num : nums ) {
            if ( to_string(num).size() % 2 == 0 ) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    vector<int> nums = {12,345,2,6,7896};
    Solution s;
    cout << s.findNumbers(nums) << '\n';
    return 0;
}