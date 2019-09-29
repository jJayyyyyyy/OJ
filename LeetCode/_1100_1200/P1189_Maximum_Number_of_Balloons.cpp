/*
https://leetcode.com/problems/maximum-number-of-balloons/description/?goto=old

输入1：字符串 text
输出：text 中的字符可以组成多少个 "balloon"
注： text 每个字符的顺序可以换, 但是每个字符只能用一次

同类题目 P1189

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> char_map;
        for ( char ch : text ) {
            char_map[ch]++;
        }

        int cnt = 0;
        bool flag = true;
        vector<char> ballon = {'b', 'a', 'l', 'l', 'o', 'o', 'n'};
        while ( flag == true ) {
            for ( char ch : ballon ) {
                if ( char_map[ch] > 0 ) {
                    char_map[ch]--;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if ( flag == true ) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.maxNumberOfBalloons("nlaebolko") << '\n';
    cout << s.maxNumberOfBalloons("loonbalxballpoon") << '\n';
    cout << s.maxNumberOfBalloons("leetcode") << '\n';

    return 0;
}