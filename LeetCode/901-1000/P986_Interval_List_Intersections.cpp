/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/?goto=old

数集交集
双指针 同类题目 P986, P167, P088

输入：两个 list：A和B, A和B的每个元素都是一个 [x, y], 表示数集区间，且A和B的区间都是从小到大排好的，A的区间没有重叠，B的区间也没有重叠
处理：求出A和B表示区间的交集
输出：A和B表示区间的交集

思路：双指针
https://leetcode.com/problems/interval-list-intersections/solution/

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int lenA = A.size();
        int lenB = B.size();
        int i = 0, j = 0;
        vector< vector<int> > ans;
        while ( i < lenA && j < lenB ) {
            int lA = A[i][0], rA = A[i][1];
            int lB = B[j][0], rB = B[j][1];
            int left = max(lA, lB);
            int right = min(rA, rB);
            // 去掉空区间
            if ( left <= right ) {
                ans.push_back({left, right});
            }

            if ( rA < rB ) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};

















