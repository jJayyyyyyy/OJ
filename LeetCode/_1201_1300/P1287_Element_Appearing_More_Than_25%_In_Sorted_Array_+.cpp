/*
https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?goto=old

输入：一个排好序的数组 arr, 非降序. 设 length = arr.size()
处理：只有一个元素值 ele 出现的次数超过了 arr.size() / 4, 找出这个元素
输出：输出出现次数超过 arr.size() / 4 的元素

举例
输入：arr = [1, 2, 2, 6, 6, 6, 6, 7, 10]
处理：arr.size() = 9,  而 6 出现了 4 次
输出：6

同类题目 P1287

方法1是直接遍历，复杂度 O(N)

方法2的参考思路如下

https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/discuss/454060/Concise-O(logn)-solution-using-C++-(beat-90)


由于 arr 已经排好序，而 ele 出现频率超过 length / 4 因此 ele 肯定会出现在以下位置之一
v1 = arr[length * 1/4]
v2 = arr[length * 2/4]
v3 = arr[length * 3/4]

在 arr 中用二分法分别查找 v1, v2, v3 连续出现的长度
若长度大于 length / 4 则该 v 就是 ele

时间复杂度 O(lg n)
空间复杂度 O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int> & arr) {
        int length = arr.size();
        vector<int> candidate_list = {arr[length/4], arr[length/2], arr[length*3/4]};
        for ( int & candidate : candidate_list ) {
            vector<int>::iterator start = lower_bound(arr.begin(), arr.end(), candidate);
            vector<int>::iterator end = upper_bound(arr.begin(), arr.end(), candidate);
            if ( end - start > length / 4 ) {
                return candidate;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    Solution s;
    s.findSpecialInteger(arr);
    return 0;
}