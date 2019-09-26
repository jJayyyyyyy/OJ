/*
https://leetcode.com/problems/minimum-absolute-difference/description/?goto=old

输入：一个数组 arr, 每个元素都不相同
处理：计算每两个元素的绝对差值 abs_diff ，得到最小的绝对差值 min_abs_diff
输出：所有 abs_diff == min_abs_diff 的 pairs

举例
输入：arr = [4, 2, 1, 5, 7, 11]
处理：可以得到 min_abs_diff = 1, 如 2-1=1, 5-4=1
输出：[[1, 2], [4, 5]]

同类题目 P1200

1. 先升序排序
2. 遍历，找到 min_abs_diff
3. 再遍历，得到输出

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_abs_diff = 0x3fffffff;
        int n0 = arr[0];
        int length = arr.size();

        for ( int i = 1; i < length; i++ ) {
            int n1 = arr[i];
            min_abs_diff = min(min_abs_diff, n1 - n0);
            n0 = n1;
        }

        vector<vector<int> > ans;
        n0 = arr[0];
        for ( int i = 1; i < length; i++ ) {
            int n1 = arr[i];
            if ( n1 - n0 == min_abs_diff ) {
                // vector<int> pair = {n0, n1};
                ans.push_back({n0, n1});
            }
            n0 = n1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,2,1,3};
    Solution s;
    s.minimumAbsDifference(nums);
    return 0;
}