/*
https://leetcode.com/problems/unique-number-of-occurrences/description/?goto=old
输入一个数组，统计每个数字出现的次数 occurrence, 判断 occurrence 是否出现重复
同类题目 P1207

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool uniqueOccurrences(vector<int> & arr) {
        unordered_map<int, int> occurrence;
        for ( int & ele : arr ) {
            occurrence[ele]++;
        }

        unordered_set<int> s;
        for ( auto it : occurrence ) {
            int cnt = it.second;
            if ( s.find(cnt) == s.end() ) {
                s.insert(cnt);
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> arr{1, 2, 3};
    Solution s;
    s.uniqueOccurrences(arr);
    return 0;
}