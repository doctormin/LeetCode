//https://leetcode.com/problems/search-in-a-binary-search-tree/
/**
 * 这道题不难，要返回BST中待搜索值为root的子树
 */

//Definition for a binary tree node.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        return __searchBST(root, val);
    }
private:
    TreeNode* __searchBST(TreeNode* root, int val){
        if(root == nullptr)
            return nullptr;
        if(root->val == val)
            return root;
        if(root->val > val)
            return __searchBST(root->left, val);
        else
            return __searchBST(root->right, val);
    }
};