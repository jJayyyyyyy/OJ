/*
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
输入：一个数组 arr，元素都是整数，1 <= arr.length <= 500, 0 <= arr[i] <= 10^4
过程：对 arr 进行排序，规则是按照元素二进制形式中 1 的数量从少到多排序，如果 1 的数量相同，则按照元素大小排序
输出：排序后的数组

同类题目 P1356

参考思路：
利用 sort 进行排序，修改 cmp 方法，使其符合题目排序规则
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int cntOne(int a)
    {
        int cnt = 0;
        for (int i = 0; i < 32; i++ )
        {
            if ( a & 0x01 )
            {
                cnt++;
            }
            a >>= 1;
        }
        return cnt;
    }
    static int cmp(int a, int b)
    {
        int cnta = cntOne(a);
        int cntb = cntOne(b);
        if ( cnta != cntb )
        {
            return cnta < cntb;
        }
        else
        {
            return a < b;
        }
    }
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};