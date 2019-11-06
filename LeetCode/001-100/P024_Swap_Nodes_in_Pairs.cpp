/*
https://leetcode.com/problems/swap-nodes-in-pairs/description/?goto=old

罗马数字与阿拉伯数字的转换 同类题目 P024

输入：链表头结点
过程：每隔两个结点，进行结点交换
输出：交换后的头结点
样例：
Given 1->2->3->4, you should return the list as 2->1->4->3.


思路:
三指针
pre, now, after

pre 用于定位开始交换的位置 now, 即 now = pre->next
然后就是常规的 交换 now 和 after, 其中 after = now->next

*/

#include <iostream>
#include <vector>
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
    ListNode* swapPairs(ListNode* head) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }

        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *pre = &dummyHead;
        ListNode *now = pre->next;
        ListNode *after = now->next;
        while ( now && after ) {
            now->next = after->next;
            after->next = now;
            pre->next = after;

            pre = now;
            now = pre->next;
            if ( now ) {
                after = now->next;
            }
        }
        return dummyHead.next;
    }
};
