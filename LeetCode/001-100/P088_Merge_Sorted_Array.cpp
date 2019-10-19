/*
https://leetcode.com/problems/merge-sorted-array/description/?goto=old

双指针归并排序
双指针 同类题目 P088, P021, P977, P986

思路：从两个数组的【最后一个】元素逐次向前，两两对比
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n) {
        int endpoint = n + m - 1;
        int i = m - 1, j = n - 1;
        while ( i >= 0 && j >= 0 ) {
            int x = nums1[i];
            int y = nums2[j];
            if ( x > y ) {
                nums1[endpoint--] = x;
                i--;
            }
            else {
                nums1[endpoint--] = y;
                j--;
            }
        }
        while ( i >= 0 ) {
            nums1[endpoint--] = nums1[i--];
        }
        while ( j >= 0 ) {
            nums1[endpoint--] = nums2[j--];
        }
    }
};

