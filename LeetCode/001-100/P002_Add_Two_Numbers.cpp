/*
https://leetcode.com/problems/add-two-numbers/description/
输入: 两个链表的头结点 l1, l2, 分别代表 num1 和 num2. 链表 l1, l2 中每一个结点表示一位数字, 链表整体表示一个倒序的数字, 即 2 -> 4 -> 3 表示 342
输出: 一个链表的头结点 head
要求: head 指向的链表同样以倒序表示了一个数字 sum, 且 sum = num1 + num2

Example:
Input: l1 = [2, 4, 3], l2 = [5, 6, 4] ===> num1 == 342, num2 == 465
Output: [7, 0, 8] ===> sum == 807 == num1 + num2
Explanation: 342 + 465 = 807

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int v) : val(v), next(NULL) {}
    ListNode(int v, ListNode * n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode();
        ListNode *now = dummyHead;
        int carry = 0;
        while ( l1 && l2 ) {
            int sum = l1->val + l2->val + carry;
            if ( sum >= 10 ) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            now->next = new ListNode(sum);
            now = now->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while ( l1 ) {
            int sum = l1->val + carry;
            if ( sum >= 10 ) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            now->next = new ListNode(sum);
            now = now->next
            l1 = l1->next;
        }

        while ( l2 ) {
            int sum = l2->val + carry;
            if ( sum >= 10 ) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            now->next = new ListNode(sum);
            now = now->next
            l2 = l2->next;
        }

        if ( carry ) {
            now->next = new ListNode(carry);
        }

        return dummyHead->next;
    }

    ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = l1;
        ListNode *now = dummyHead;
        int carry = 0;
        while ( l1 || l2 || carry ) {
            int sum = carry;
            if ( l1 ) {
                sum += l1->val;
                l1 = l1->next;
            }
            if ( l2 ) {
                sum += l2->val;
                l2 = l2->next;
            }

            if ( sum >= 10 ) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            now->next = new ListNode(sum);
            now = now->next;
        }

        return head->next;
    }
};

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    Solution s;
    ListNode *head = s.addTwoNumbers(l1, l2);
    while( head != NULL ){
        cout<<head->val;
        head = head->next;
    }
    return 0;
}
