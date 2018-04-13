/*
 * https://leetcode.com/problems/two-sum/description/
 * 给定一个vector，找出和为target的两个元素，构成新的vector并返回
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        for( int i = 0; i < nums.size(); ++i ){
            for( int j = i + 1; j < nums.size(); ++j ){
                if( nums[i] + nums[j] == target ){
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }
};