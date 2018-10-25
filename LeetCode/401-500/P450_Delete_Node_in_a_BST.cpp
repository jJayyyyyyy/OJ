/*
https://leetcode.com/problems/delete-node-in-a-bst/description/
删除BST的某一个结点
同类题目: P450, P669

存疑，本题如何检测结果？仅看中序是否一致？还是对比整棵数的结构？
应该是后者，因为题目描述中已经告诉我们结果可能有多种树型，但是没有明确表示该用那个结点来填补被删除的结点

加图片
.../LeetCode/Visualization/P450_...._.jpg

参考思路1
https://leetcode.com/problems/delete-node-in-a-bst/discuss/93293/Very-Concise-C++-Solution-for-General-Binary-Tree-not-only-BST

参考思路2
sample 20 ms submission

*/

#include <iostream>
using namespace std;

/*
把右子树最小的结点拿上来了，整体结构基本没变

先交换，把root->val放到下面去
再向下找到root->val，删除

避免了寻找 root->parent
*/
class Solution1 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);    
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};

// 先找到待删除结点
// 大大改变了树的结构，把root->right 接到 root->leftmax 的右边
// 就看 题目的测试方式了，是看结构，还是看顺序
class Solution2 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
        	// 若只有一个孩子，则返回这个孩子，同时删除 root
        	// 用return，免去了寻找parent
            if ( root->left == NULL ) {
            	TreeNode * right = root->right;
            	delete root;
                return right;
            }else if (root->right == NULL ) {
            	TreeNode * left = root->left;
            	delete root;
                return left;
            }
            
            TreeNode * lmax = root->left;
            while (lmax->right){
            	lmax = lmax->right;	
            }
            lmax->right = root->right;
            return root->left;
        }
    }
};