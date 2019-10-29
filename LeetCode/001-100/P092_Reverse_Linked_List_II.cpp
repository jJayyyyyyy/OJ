/*
https://leetcode.com/problems/reverse-linked-list-ii/description/?goto=old

反转链表 同类题目 P092, P206

输入：链表头结点, 反转起点m, 反转终点n
过程：将链表中，m到n的一段反转，要求在一次遍历中完成
输出：反转后链表的头结点

思路: 头插法

*/

#include <iostream>
using namespace std;

// io加速
static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummyhead = ListNode(0);
        dummyhead.next = head;
        ListNode *pre = &dummyhead;
        ListNode *p = head;
        int cnt = 0;
        while ( p != NULL ) {
            cnt++;
            if ( cnt == m ) {
                break;
            }
            pre = pre->next;
            p = p->next;
        }
        int len = n - m;
        for ( int i = 0; i < len; i++ ) {
            ListNode * tmp = pre->next;
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = tmp;
        }
        return dummyhead.next;
    }
};

int main() {
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
//    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
    Solution s;
    s.reverseBetween(head, 1, 2);
    return 0;
}
