/*
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/?goto=old
输入一个数 n, 1 <= n <= 10^5
将 n 每一位的 digit 相乘得到 p, 将 n 每一位的 digit 相加得到 s
返回 result = p - s

同类题目 P1281

由于不知道有几个 digit (1~5)
所以从高位到低位不是很好算
因此不如从低位到高位，反正乘法和加法满足交换率

当然也可以先把数字转换成字符串，然后求长度，再从高位到低位计算
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        while ( n != 0 ){
            int digit = n % 10;
            p *= digit;
            s += digit;
            n /= 10;
        }
        return (p - s);
    }
};

int main(){
    Solution s;
    cout << s.subtractProductAndSum(4421) << '\n';
    return 0;
}