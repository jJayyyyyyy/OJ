/*
https://leetcode.com/problems/decompress-run-length-encoded-list/description/?goto=old

同类题目 P1313

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int> & nums) {
        vector<int> res;
        int len = nums.size();
        if ( len < 2 || len % 2 != 0 ) {
            return res;
        }

        for ( int i = 0; i < len; i += 2 ) {
            int freq = nums[i];
            int val = nums[i + 1];
            for ( int j = 0; j < freq; j++ ) {
                res.push_back(val);
            }
        }
        return res;
    }
};
