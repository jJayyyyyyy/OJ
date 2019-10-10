/*
https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/?goto=old

同类题目 P1237

题目有点绕，大概意思是说
给定一个非减函数 f(x, y)
但是你不知道它内部到底是个啥，就只有这么一个接口
然后给一个 z
现在要求出 0 < x, y <= 1000 的所有正整数解的集合 (x, y)

*/

#include <iostream>
#include <vector>
using namespace std;

/*
// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};
*/

class Solution {
public:
    // 最直接的方法，暴力搜索，（直接忽略非减函数这个条件）
    vector<vector<int>> findSolution1(CustomFunction & customfunction, int z) {
        vector< vector<int> > res;
        for ( int x = 1; x <= 1000; x++ ) {
            for ( int y = 1; y <= 1000; y++ ) {
                if ( customfunction.f(x, y) == z ) {
                    res.push_back({x, y});
                }
            }
        }
        return res;
    }


    /*
    利用非减函数的特点，双重循环的内层循环起点可以逐渐变小，减少不必要的计算
    参考思路 https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/discuss/414249/JavaC++Python-O(X+Y)
    */
    vector<vector<int>> findSolution(CustomFunction & customfunction, int z) {
        vector< vector<int> > res;
        int y = 1000;
        for ( int x = 1; x <= 1000; x++ ) {
            while ( y > 1 && customfunction.f(x, y) > z ) {
                y--;
            }
            if ( customfunction.f(x, y) == z ) {
                res.push_back({x, y});
            }
        }
        return res;
    }
};
