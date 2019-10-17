/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/?goto=old


双指针 同类题目 P167, P633, P345, P680, P088, P141, P524, P653

输入：根结点root, 目标值 target
处理：判断 BST 中是否存在这样的两个结点，它们的值的和等于 target
输出：true / false

思路：
1. 先按中序遍历 BST，得到递增数组
2. 双指针夹逼（P167）

*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> number_list;

    void in_order_traverse(TreeNode * root) {
        if ( NULL != root ) {
            in_order_traverse(root->left);
            number_list.push_back(root->val);
            in_order_traverse(root->right);
        }
    }

public:
    bool findTarget(TreeNode* root, int target) {
        in_order_traverse(root);
        int len = number_list.size();
        if ( len <= 1 ) {
            return false;
        }

        int i = 0, j = len - 1;
        while ( i != j ) {
            int sum = number_list[i] + number_list[j];
            if ( sum > target ) {
                j--;
            }
            else if ( sum < target ) {
                i++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};