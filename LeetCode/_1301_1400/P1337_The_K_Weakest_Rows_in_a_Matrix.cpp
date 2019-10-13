/*
https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/?goto=old

同类题目 P1337

一个矩阵，元素只含 0 和 1，且每一行都是 1 在前，0 在后
现在要求找出 1 最少的 k 行
行标从 0 开始
结果是行标的序列，1 较少的行标排前面
如果某两行 1 的数量相同，则小行标排前面

思路
二分法求出第 i 行中值为 1 的元素个数 n，与行号一起组成元组 <n, i>，然后 push_back() 到一个 vec
使用 sort 对 vec 排序(自定义 comp 函数)

g++ main.cpp --std=c++11 -o main
./main

*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

static const auto io_speed_up = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
};

class Solution {
private:
    static bool comp(pair<int, int> & a, pair<int, int> & b) {
        if ( a.first != b.first ) {
            return a.first < b.first;
        }
        else {
            return a.second < b.second;
        }
    }
public:
    vector<int> kWeakestRows(vector<vector<int> > & mat, int k) {
        int nRow = mat.size();
        int nCol = mat[0].size();
        vector<pair<int, int> > vec;
        for ( int i = 0; i < nRow; i++ ) {
            const vector<int> & line = mat[i];
            // 由于题目中的 n 很小, 所以其实可以不用二分法, 直接顺序查找也很快
            int cntOnes = line.rend() - upper_bound(line.rbegin(), line.rend(), 0);
            vec.push_back({cntOnes, i});
        }
        sort(vec.begin(), vec.end());
        vector<int> res(k, 0);
        for ( int i = 0; i < k; i++ ) {
            res[i] = vec[i].second;
        }
        return res;
    }
};

int main() {
    vector<vector<int> > mat;
    mat.push_back({1, 0, 0, 0});
    mat.push_back({1, 1, 1, 1});
    mat.push_back({1, 0, 0, 0});
    mat.push_back({1, 1, 0, 0});

    Solution s;
    int k = 2;
    vector<int> res = s.kWeakestRows(mat, k);
    for ( int i = 0; i < k; i++ ) {
        cout << res[i] << '\n';
    }
    return 0;
}
