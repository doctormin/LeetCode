//https://leetcode.com/problems/count-complete-tree-nodes/
/**
 * 题目：计算一颗完全二叉树的节点个数
 * 思路：1.递归 2.BFS 3.计算最左节点深度和最右节点深度，如果相等就返回(1<<h)-1
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
//way1 - BFS，直接无脑
/*
#include<queue>
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr)
            return 0;
        int count = 0;
        q.push(root);
        ++count;
        while(not q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left != nullptr){
                q.push(node->left);
                ++count;
            }
            if(node->right != nullptr){
                q.push(node->right);
                ++count;
            }
        }
        return count;
    }
};*/
//way2 - 巧妙计算
class Solution {
    public:
        int countNodes(TreeNode* root){
            int lh = leftHeight(root);
            int rh = rightHeight(root);
            return (lh == rh) ? (1 << lh) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
        }
    private:
        int leftHeight(TreeNode* root){
            return root == nullptr ? 0 : 1 + leftHeight(root->left);
        }
        int rightHeight(TreeNode* root){
            return root == nullptr ? 0 : 1 + rightHeight(root->right);
        }
};





