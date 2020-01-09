/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
输入: 字符串 s, which consists of English letters, digits, symbols and spaces. 即字符串可以由各种 ascii 字符组成
输出: 子字符串 substr 的长度
要求: 找出最长的 substr, 且 substr 不包含重复字符
说明: 子字符串是原字符串 s 中连续的一段字符串

思路1: 暴力搜素, 见 lengthOfLongestSubstring_BF()
以字符串的每一个字符为起点, 向后寻找尽量长的距离, 使形成的 substr 满足要求

思路1存在的的问题: 
内循环中的 end, 每次从 begin+1 开始, 这其实是不必要的, 因为从 begin+1 到当前的 end, 已经被证明是不存在重复元素的, 且长度肯定小于 maxLen, 因此 end 直接从 end+1 开始即可, 从而避免大量的重复计算, 提高效率

思路2: 优化思路1, 滑动窗口 Sliding Window 1
举例
     begin=0
     v
s = "abcbbbabcc"
      ^^^
        end=3, 此时发现了重复字符 b
下一步, begin = begin + 1
然后, end 从 end + 1 开始, 而不是从 begin + 1 开始, 因为 [begin + 1, end] 肯定是不重复且短于 [begin, end] 的长度的


思路3: 优化思路2, 滑动窗口 Sliding Window 2
参考 [这里](https://discuss.leetcode.com/topic/24739/c-code-in-9-lines)
举例

        begin=3+1
     begin=0
     v  v
s = "adebcbbbabcc"
      ^^^^^
          end=5,

          此时发现了重复字符 b, 将窗口的左边界直接跳跃到字符 b 最后一次出现的下标的后方, 即下标为 3+1 的地方, 而不是从 begin+1 = 0+1 的下标开始

附注: 此时还要判断最后一次出现的下标 3 是否在 begin 之前
举例

       begin
       v
     v
s = "abba"
      ^^
        ^
        end
        此时虽然发现了 a 是重复字符, 最后一次出现的下标为 0, 但是由于左边界 begin 已经移动到了下标 2, 因此位于 2 之前的 [最后一次出现的下标] 都已经作废 (substr 从 begin 开始算起, 因此在 begin 之前的 [最后一次出现的下标] 已经失去意义)
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    // Solution1, BF
    int lengthOfLongestSubstring_BF(string s) {
        int size = s.size();
        if ( size < 2 ) {
            return size;
        }

        int maxLen = 0;
        unordered_set<char> uset;
        for ( int begin = 0; begin < size; begin++ ) {
            for ( int end = begin; end < size; end++ ) {
                char ch = s[end];
                if ( uset.find(ch) == uset.end() ) {
                    uset.insert(ch);
                    int len = end - begin + 1;
                    maxLen = maxLen > len ? maxLen : len;
                }
                else {
                    uset.clear();
                    break;
                }
            }
        }
        return maxLen;
    }

    // Sliding Window
    int lengthOfLongestSubstring_SW2(string s) {
        int size = s.size();
        int maxLen = 0;
        unordered_map<char, int> last_index_of;
        int begin = 0, end = 0;
        for ( ; begin < size && end < size; ) {
            char ch = s[end];
            if ( last_index_of.find(ch) == last_index_of.end() || last_index_of[ch] < begin ) {
                int len = end - begin + 1;
                maxLen = maxLen > len ? maxLen : len;
                last_index_of[ch] = end;
                end++;
            }
            else {
                begin = last_index_of[ch] + 1;
                int len = end - begin + 1;
                maxLen = maxLen > len ? maxLen : len;
                last_index_of[ch] = end;
                end++;
            }
        }
        return maxLen;
    }

    // Sliding Window
    // 参考 [这里](https://discuss.leetcode.com/topic/24739/c-code-in-9-lines)
    int lengthOfLongestSubstring(string s) {
        vector<int> Hash(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (Hash[ch] > start)
                start = Hash[ch];
            Hash[ch] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main() {
    Solution s;

    // test cases
    string str = ""
    // string str = "a"
    // string str = "aa"
    // string str = "abc"
    // string str = "abcabcbb"
    // string str = "abcbbb"
    // string str = "abba"

    s.lengthOfLongestSubstring_SW2(str);
    return 0;
}