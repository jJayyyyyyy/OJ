/*
https://leetcode.com/problems/merge-k-sorted-lists/description/
指针形式的归并排序, 与 P021 不同的是, 本题要求合并 k 个链表
同类题目: P021, P023

参考思路
https://leetcode.com/problems/merge-k-sorted-lists/solution/
Approach 4: Merge lists one by one

也就是说, 利用 P021 的 mergeTwoLists, 两两合并链表, 直到全部合并完成
但是直接从 0-1 的按下标顺序的合并太慢了
因为累积到后面的链太长了, 每一次都要完全遍历一整条长链

我们还可以优化, 也就是像哈夫曼树/shannon fano algorithm一样, 先两两合并小的链, 再逐渐合并成为长链
而不是不停地在长链上增加小链

*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummyhead(INT_MIN);
    ListNode * tail = & dummyhead;

    while( l1 != NULL && l2 != NULL ) {
        if( l1->val < l2->val ){
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if( l1 != NULL ){
        tail->next = l1;
    }
    else{
        tail->next = l2;
    }
    return dummyhead.next;
}

// 优化前的做法, 164 ms
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        ListNode * head = NULL;
        if( len == 0 ){
            
        }
        else if( len == 1 ){
            head = lists[0];
        }
        else{
            // 不停地在长链上增加小链
            head = mergeTwoLists(lists[0], lists[1]);
            for( int i = 2; i < len; i++ ){
                head = mergeTwoLists(head, lists[i]);
            }
        }
        return head;
    }
};

// 优化后的做法, 20 ms
// 把第1链(left)和倒数第1链(right)合并到 left
// 再把起点left设为0，重新开始归并
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        ListNode * head = NULL;
        if( len == 0 ){
            return NULL;
        }
        else if( len == 1 ){
            head = lists[0];
        }
        else{
            int left = 0, right = len - 1;
            // 先两两合并, 再逐渐合并成为长链
            // 而不是直接全部都合到一条链上
            // 具体做法，第1链和最后1链合并，第2链和最后第2链合并，……
            while( right != 0 ){
                while( left < right ){
                    lists[left] = mergeTwoLists(lists[left], lists[right]);
                    left++;
                    right--;
                }
                left = 0;
            }
            head = lists[0];
        }
        return head;
    }
};
