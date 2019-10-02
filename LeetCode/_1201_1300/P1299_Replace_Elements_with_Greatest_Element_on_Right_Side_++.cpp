/*
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/?goto=old

输入： 数组 arr
输出： 数组 ans

要求：
1. 1 <= arr.length <= 10^4
2. 1 <= arr[i] <= 10^5
3. 对于 arr[i], 找出 arr[i:] 中最大的元素 max_right, 然后使 arr[i] = max_right
4. arr[-1] = -1

例
输入： arr = [17,18,5,4,6,1]
输出： ans = [18,6,6,6,1,-1]


同类题目 P1299
思路1： Brute Force (TLE)
双重循环，外层遍历 arr[:], 内层遍历 arr[i+1:] 找最大值
时间复杂度 O(N^2)

思路2： 逆向思维
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/discuss/463249/JavaC++Python-Straight-Forward
从后往前 traverse
每次更新 max_part
最大程度重用 max_part，而不是每次从头去找

时间复杂度 O(N)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size(), max_right = -1;
        vector<int> res = arr;
        for ( int i = size - 1; i >= 0; i-- ) {
            res[i] = max_right;
            max_right = max(max_right, arr[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {17,18,5,4,6,1};
    s.replaceElements(arr);
    return 0;
}