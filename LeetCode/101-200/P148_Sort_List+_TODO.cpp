/*
https://leetcode.com/problems/sort-list/description/?goto=old

同类题目 P148


参考思路：https://leetcode.com/problems/sort-list/discuss/166324/c++-and-java-legit-solution.-O(nlogn)-time-and-O(1)-space!-No-recursion!-With-detailed-explaination
大致意思是说，题目要求时间 O(nlgn) 空间 O(1), 那么只有归并排序满足要求。
先把原链表拆成两两一组，每个组归并排序。然后变成四四一组，继续归并排序。
重复以上动作直到只剩一个大组

不过，要做到时间 O(nlgn) 空间 O(1), 这个解法很复杂，而且实际运行效率不一定高。
因此只理解其思路即可。

首先要快速AC
1. 链表变数组，然后快排
2. 链表插入排序（从第二个结点开始，把该结点插入到前面已排序链表中合适的位置）


TODO:
符合题目要求的解法

*/

#include <iostream>
#include <vector>
using namespace std;

static const auto io_speed_up = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if ( NULL == head || NULL == head->next ) {
            return head;
        }

        vector<int> arr;
        ListNode * p = head;
        while ( p != NULL ) {
            arr.push_back(p->val);
            p = p->next;
        }
        sort(arr.begin(), arr.end());
        p = head;
        for ( int i = 0; i < arr.size(); i++ ) {
            p->val = arr[i];
            p = p->next;
        }
        return head;
    }
};
