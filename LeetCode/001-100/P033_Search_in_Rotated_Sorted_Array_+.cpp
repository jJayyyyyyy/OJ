/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/?goto=old

二分查找 同类题目 P033

输入1：有序列表 nums, 然后对 nums 在某个结点进行循环位移, 使 nums 变成 rotated sorted array;
输入2：target
过程：在 nums 中查找 target, 且时间复杂度不超过 O(lgn)
输出：target 在 nums 中的位置, 若不存在则返回 -1

样例1：
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

样例2：
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1



思路:
https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution

两次二分查找
第一次，先找到 nums 最小值所在位置，也就是旋转轴点。
由此，轴点前后分别是有序的
再进行第二次二分查找


*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
private:
    int getPivot(vector<int> const & nums, int target, int lo, int hi) {
        while ( lo < hi ) {
            int mid = (lo + hi) / 2;
            if ( nums[mid] > nums[hi] ) {
                // 中点比右端点大，说明轴点在中点右边
                // [4, 5, 6,   7,    0, 1, 2]
                //  lo        mid   min    hi
                lo = mid + 1;
            }
            else{
                // 中点比右端点小，说明轴点在中点左边
                // [5, 6, 7,   0,    1, 2, 4]
                //  lo        mid          hi
                //            min
                hi = mid;
                // 不是 hi = mid - 1
            }
        }
        int pivot = hi;
        return pivot;
    }

    int bsearch(vector<int> const & nums, int target, int lo, int hi) {
        while ( lo <= hi ) {
            int mid = ( lo + hi ) / 2;
            int val = nums[mid];
            if ( target > val ) {
                lo = mid + 1;
            }
            else if ( target < val ) {
                hi = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if ( len == 0 ) {
            return -1;
        }
        int lo = 0, hi = len - 1;
        
        // 此时 lo == hi == mid == pos_min
        int pos_min = getPivot(nums, target, lo, hi);

        if ( pos_min == 0 ) {
            return bsearch(nums, target, lo, hi);
        }
        else {
            // pos_min >= 1
            int pos_target = bsearch(nums, target, lo, pos_min - 1);
            if ( pos_target == -1 ) {
                return bsearch(nums, target, pos_min, hi);
            }
            else {
                return pos_target;
            }
        }
    }
};

int main () {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target1 = 0;
    int target2 = 3;
    s.search(nums, target1);
    s.search(nums, target2);
    return 0;
}