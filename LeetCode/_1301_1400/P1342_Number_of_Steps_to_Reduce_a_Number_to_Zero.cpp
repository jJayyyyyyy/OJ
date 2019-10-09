/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/?goto=old

同类题目 P1342

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while ( num != 0 ) {
            if ( (num & 0x01) == 1 ) {
                num -= 1;
            }
            else {
                num >>= 1;
            }
            cnt++;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.numberOfSteps(14) << '\n';
    cout << s.numberOfSteps(8) << '\n';
    cout << s.numberOfSteps(123) << '\n';

    return 0;
}
