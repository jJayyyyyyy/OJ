/*
https://leetcode.com/problems/rank-transform-of-an-array/description/?goto=old

同类题目 P1331

一个数组 arr，可能包含重复元素
对于其中的每个元素 ele, 求出 arr 中比 ele 小的元素的个数

思路
先通过 set 进行去重和排序，然后把 set 复制到 arr2, 接着二分查找

复杂度
n * lgn


优化:
从小到大一次遍历，依次利用小的值的rank记录大的值的rank，避免重复二分查找

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

static const auto io_speed_up = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
};

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        vector<int> arr2(s.begin(), s.end()), res;
        for ( const int & val : arr ) {
            int rank = lower_bound(arr2.begin(), arr2.end(), val) - arr2.begin() + 1;
            res.push_back(rank);
        }
        return res;
    }

    vector<int> arrayRankTransform_opt(vector<int>& arr) {
        vector<int> vec(arr);
        sort(vec.begin(), vec.end());
        unordered_map<int, int> rank;
        for ( const int & val : vec ) {
            if ( rank.find(val) == rank.end() ) {
                rank[val] = rank.size() + 1;
            }

            // 或者
            // rank.emplace(val, rank.size() + 1);
        }
        for ( int & val : arr ) {
            val = rank[val];
        }
        return arr;
    }
};

int main() {
    // map.emplace 是当元素不存在的时候插入，存在时就不插入了
    unordered_map<int, int> m;
    m.insert(1,1);
    m.insert(1,2);
    cout << m[1] << '\n';  // 1
    return 0;
}