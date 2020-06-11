// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * 本题要寻找BST中的第k小的元素
 * 直接无脑中序遍历，时间复杂度O(k)
 */
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
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int result;
        middle_order(root, counter, k, result);
        return result;
    }
private:
    void middle_order(TreeNode* root, int &counter, int k, int &result){
        if(root->left){
            //cout << "going left " << root->left->val << endl;
            middle_order(root->left, counter, k, result);
        }
        //cout << "right here " << root->val << endl;
        if(++counter == k){
            result = root->val;
            return;
        }
        if(root->right){
            //cout << "going right " << root->right->val << endl;
            middle_order(root->right, counter, k, result);
        }
           
    }
};