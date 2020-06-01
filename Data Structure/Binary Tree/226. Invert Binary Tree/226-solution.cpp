// https://leetcode.com/problems/invert-binary-tree
/*
算法思路：
    要invert二叉树，那么首先就递归进行left和right的交换就行
*/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        invert(root);
        return root;
    }
    void invert(TreeNode* root){
        if(root->left)
            invert(root->left);
        if(root->right)
            invert(root->right);
        auto tmp    = root->left;
        root->left  = root->right;
        root->right = tmp;
    }
};