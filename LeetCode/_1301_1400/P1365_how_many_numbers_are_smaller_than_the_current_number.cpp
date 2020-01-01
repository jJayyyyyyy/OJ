/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
输入: 一个数组 nums[], 元素都是整数, 2 <= nums.length <= 500, 0 <= nums[i] <= 100
输出: 一个数组 res[], 元素都是整数
要求: 对于 num[i], 统计出 nums[] 中满足所有 requirement 的 nums[j] 的个数 cnt, 然后使 res[i] = cnt. 其中, requirement 如下
req1: nums[j] < nums[i]
req2: j != i


同类题目 P1365

参考思路:
0. 桶排序.
1. 由于 nums 的元素大小在 [0, 100] 这个区间, 因此可以新建统计桶 counter[128], 然后遍历 nums[], 对于 num = nums[i], counter[num]++ 
2. 由此得到的 counter 的含义是, counter[num] 代表了 nums[] 中值为 num 的元素的个数
3. 由此可以得到 nums[] 中, 值比 num 小的元素的总个数为 [0, num-1]Σcounter[i]

*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    	// 用于统计的桶
        // counter[num] 代表了 nums[] 中值为 num 的元素的个数
        vector<int> counter(128, 0);
        for ( int num : nums ) {
            counter[num]++;
        }

        // countSmaller[num] 表示了 nums[] 里面, 值比 num 小的元素的个数
        vector<int> countSmaller(128, 0);
        int cntSmaller = 0;
        for ( int num = 1; num <= 100; num++ ) {
            cntSmaller += counter[num - 1];
            countSmaller[num] = cntSmaller;
        }

        // countSmaller[num] 代表了 nums[] 里面, 值比 num = nums[i] 小的元素的个数, 因此将其填入 res[i]
        int size = nums.size();
        vector<int> res(size, 0);
        for ( int i = 0; i < size; i++ ) {
            int num = nums[i];
            int cntSmaller = countSmaller[num];
            res[i] = cntSmaller;
        }
        return res;
    }
};
