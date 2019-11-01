/*
 https://leetcode.com/problems/restore-ip-addresses/description/?goto=old
 
 反转链表 同类题目 P093
 
 输入：字符串形式的IP地址（没有分隔符）s， 如 "25525511135"
 过程：对 s 添加分隔符 '.', 使之成为合法的 IP 地址，形成IP列表ans，
 输出：ans，形如 ["255.255.11.135", "255.255.111.35"]
 
 思路:
 0. 首先检查 s 的长度, 大于 12 的就丢弃了
 1. 尝试将s分成四组, 每组至少1个字符，至多3个字符
 2. 每一组的字符串都转换成数字 nip = stoi(subsip)
 3. 判断各个 nip 是否在 0~255 之间
 4. 记录符合规则的nip
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// } ();

class Solution {
private:
    bool is_valid_range(string s) {
        int nip = stoi(s);
        string sip = to_string(nip);
        return nip >= 0 && nip <= 255 && sip == s;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> ans;
        if ( len < 4 || len > 12 ) {
            return ans;
        }
        
        for ( int i = 1; i <=3; i++ ) {
            for ( int j = 1; j <= 3; j++ ) {
                for ( int k = 1; k <= 3; k++ ) {
                    int start4 = i + j + k;
                    if ( start4 >= len - 3 && start4 <= len - 1 ) {
                        string s1 = s.substr(0, i);
                        string s2 = s.substr(i, j);
                        string s3 = s.substr(i+j, k);
                        string s4 = s.substr(i+j+k);

                        if ( is_valid_range(s1) && is_valid_range(s2) && is_valid_range(s3) && is_valid_range(s4) ) {
                            
                            string valid_ip = s1 + "." + s2 + "." + s3 + "." +s4;
                            ans.push_back(valid_ip);
                        }
                    }
                }
            }
        }
//        for (auto item : ans ) {
//            cout << item << ' ';
//        }
//        cout << '\n';
        return ans;
    }
};

int main() {
    Solution s;
    s.restoreIpAddresses("25525511135");    // ["255.255.11.135", "255.255.111.35"]
    s.restoreIpAddresses("0000");           // ["0.0.0.0"]
    s.restoreIpAddresses("010010");         // ["0.10.0.10","0.100.1.0"]
    return 0;
}
