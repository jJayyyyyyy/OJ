/*
https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/description/?goto=old


同类题目 P1252
思路： 
https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/discuss/425290/C++-bool-simulation

奇怪的是 
虽然 bool 比 int 省空间， 但是 int 比 bool 快很多
是字节对齐的原因吗

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

class Solution {
public:
    int oddCells(int n, int m, vector< vector<int> > & indices) {
        vector< vector<int> > matrix(n, vector<int>(m, 0));
        // vector< vector<bool> > matrix(n, vector<bool>(m, false));
        for ( int i = 0; i < indices.size(); i++ ) {
            int row = indices[i][0];
            int col = indices[i][1];
            for ( int r = 0; r < n; r++ ) {
                matrix[r][col] ^= 1;
                // matrix[r][col] = ！matrix[r][col];
            }
            for ( int c = 0; c < m; c++ ) {
                matrix[row][c] ^= 1;
                // matrix[row][c] = !matrix[row][c];
            }
        }
        int ans = 0;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector< vector<int> > indices = {{0, 1}, {1, 1}};
    cout << s.oddCells(2, 3, indices);
    return 0;
}