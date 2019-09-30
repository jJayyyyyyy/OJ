/*
https://leetcode.com/problems/daily-temperatures/description/?goto=old

输入： 数组T，下标是日期 i，值是温度 T[i]
输出： 数组 ans
注： 每一个 j = ans[i] 表示在日期 i 之后至少再过 j 天，才会有 T[i+j] > T[i]

例
输入： T = [73, 74, 75, 71, 69, 72, 76, 73]
输出： ans = [1, 1, 4, 2, 1, 1, 0, 0]


同类题目 P739

参考思路1
Brute Force
参考 Solution_TLE


参考思路2
https://leetcode.com/problems/daily-temperatures/solution/

维护一个栈，从栈底到栈顶是升序的
压入的是下标（日期）
下标 i 对应的温度 T[i] 大的 i 在下，不断压入 T[i] 小的 i，

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> & T) {
        // Time Complexity = O(N)
        // Space Complexity = O(N)
        int size = T.size();
        vector<int> ans(size, 0);
        stack<int> s;

        for ( int i = size - 1; i >= 0; i-- ) {
            while ( !s.empty() && T[s.top()] <= T[i] ) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : (s.top() - i);
            s.push(i);
        }
        return ans;
    }
};

class Solution_TLE {
public:
    vector<int> dailyTemperatures(vector<int> & T) {
        // Time Complexity: O(N^2)
        int size = T.size();
        vector<int> ans(size, 0);
        for ( int i = 0; i < size - 1; i++ ) {
            for ( int j = i + 1; j < size; j++ ) {
                if ( T[j] > T[i] ) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    s.dailyTemperatures(T);

    return 0;
}