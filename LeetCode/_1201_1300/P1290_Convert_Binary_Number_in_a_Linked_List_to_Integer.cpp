/*
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?goto=old
二进制数转换为十进制数，其中，二进制数由链表表示
同类题目 P1290
*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode * head) {
        int decimal_val = 0;
        while ( head != NULL ) {
            decimal_val <<= 1;
            int val = head->val;
            cout << val << '\n';
            if ( val == 1 ) {
                decimal_val++;
            }
            head = head->next;
        }
        return decimal_val;
    }
};

int main(){
    ListNode * head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution s;
    cout << s.getDecimalValue(head) << '\n';
    return 0;
}