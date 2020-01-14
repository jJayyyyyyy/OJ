/*
https://leetcode.com/problems/reverse-integer/description/
给定一个整数，倒序输出。若超出32位有符号整数的范围，则返回0

*/


class Solution {
    public int reverse(int x) {
        if ( x == 0 ) {
            return 0;
        }

        int ans = 0;
        int remainder = 0;
        int INT_MAX = Integer.MAX_VALUE;
        int INT_MIN = Integer.MIN_VALUE;
        while ( x != 0 ) {
            remainder = x % 10;
            if ( ans > INT_MAX / 10 || (ans == INT_MAX / 10 && remainder > 7 ) ) {
                return 0;
            }
            if ( ans < INT_MIN / 10 || (ans == INT_MIN / 10 && remainder < -8 ) ) {
                return 0;
            }
            ans = ans * 10 + remainder;
            x /= 10;
        }
        return ans;
    }
};

/*
int main(){
    Solution s;
    std::cout<<s.reverse(-1563847412);
    return 0;
}
*/