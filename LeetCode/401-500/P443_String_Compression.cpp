/*
https://leetcode.com/problems/string-compression/description/
最简单的字符串压缩法，使用双指针
同类题目 P443, 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int compress(vector<char> & chars){
        chars.push_back(0);
        int i=0, j=1, cnt=1;
        
        while( j < chars.size() ){
            if( chars[j] != chars[j-1] ){
                if( cnt == 1 ){
                    i++;
                }else if( cnt > 1 && cnt < 10 ){
                    // i++;
                    chars[i + 1] = cnt + '0';
                    i += 2;
                }else if( cnt < 100 ){
                    chars[i + 1] = cnt / 10 + '0';
                    chars[i + 2] = cnt % 10 + '0';
                    i += 3;
                }else if( cnt < 1000 ){
                    chars[i + 1] = cnt / 100 + '0';
                    cnt %= 100;
                    chars[i + 2] = cnt / 10 + '0';
                    chars[i + 3] = cnt % 10 + '0';
                    i += 4;
                }else if( cnt < 10000 ){
                    chars[i + 1] = cnt / 1000 + '0';
                    cnt %= 1000;
                    chars[i + 2] = cnt / 100 + '0';
                    cnt %= 100;
                    chars[i + 3] = cnt / 10 + '0';
                    chars[i + 4] = cnt % 10 + '0';
                    i += 5;
                }
                chars[i] = chars[j];
                cnt = 0;
            }
            j++;
            cnt++;
        }
        return i;
    }
};

int main(){
    Solution s;
    char chs[] = {'a', 'a', 'a', 'b', 'b', 'e', 'e'};
    vector<char> v(chs, chs+7);
    
    cout<<s.compress(v)<<'\n';
    
    for( auto ch : v ){
        cout<<ch<<' ';
    }
    cout<<'\n';
    
    return 0;
}
