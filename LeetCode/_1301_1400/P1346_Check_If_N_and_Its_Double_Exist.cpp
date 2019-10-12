/*
https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?goto=old

同类题目 P1346

一个数列 arr，判断其中是否有两个元素 n, m 使得 n = 2 * m
或者
判断是否存在下标 i, j，使得
1. i != j
2. 0 <= i, j <= arr.length
3. arr[i] == arr[j] * 2

思路
bitmap

由于 arr[i] 可能为负，所以正数一个 bitmap 负数一个 bitmap
三次遍历即可，复杂度低

最后考虑边界情况，从测试用例来看，可能存在重复的元素，而且可能出现 0
因为 0 = 0 * 2，所以当出现两次 0 时即可直接 return true

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<bool> neg(1024, false);
        vector<bool> pos(1024, false);
        bool has_zero = false;
        for ( int val : arr ) {
            if ( val < 0 ) {
                neg[-val] = true;
            }
            else if ( val > 0 ) {
                pos[val] = true;
            }
            else {
                if ( has_zero == false ) {
                    has_zero = true;
                }
                else {
                    return true;
                }
            }
        }

        for ( int val = 1; val <= 500; val++ ) {
            if ( neg[val] == true && neg[val * 2] == true ) {
                return true;
            }
        }

        for ( int val = 1; val <= 500; val++ ) {
            if ( pos[val] == true && pos[val * 2] == true ) {
                return true;
            }
        }

        return false;
    }
};