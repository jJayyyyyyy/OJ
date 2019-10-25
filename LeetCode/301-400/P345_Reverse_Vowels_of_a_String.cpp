/*
https://leetcode.com/problems/reverse-vowels-of-a-string/description/
给定字符串，反转其中的元音
同类题目 P344, P345


*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        bool vowel_set[128] = {false};
        vowel_set['a'] = true;
        vowel_set['A'] = true;
        vowel_set['e'] = true;
        vowel_set['E'] = true;
        vowel_set['i'] = true;
        vowel_set['I'] = true;
        vowel_set['o'] = true;
        vowel_set['O'] = true;
        vowel_set['u'] = true;
        vowel_set['U'] = true;

        int i = 0, j = s.size() - 1;
        while( i < j ){
            if( vowel_set[ s[i] ] == false ){
                i++;
            }
            if( vowel_set[ s[j] ] == false ){
                j--;
            }
            if( i < j && vowel_set[ s[i] ] == true && vowel_set[ s[j] ] == true ){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};


int main(){
    Solution s;
    cout<<s.reverseVowels("hello")<<'\n';
    cout<<s.reverseVowels("aA")<<'\n';  // 注意大小写

    return 0;
}