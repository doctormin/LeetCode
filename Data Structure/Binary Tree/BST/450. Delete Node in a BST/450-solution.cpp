
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define IS_LEAF(node) (node->left == nullptr and node->right == nullptr)

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) 
            return root; 
        auto target = root;
        auto target_parent = root;
        while(target != nullptr and target->val != key){
            if(target->val > key){
                target_parent = target;
                target = target->left;
            }
               
            else{
                target_parent = target;
                target = target->right;
            }      
        }
        //要删除的点不存在
        if(target == nullptr)
            return root;
        //只有root这一个节点而且就是待删除的节点
        if(IS_LEAF(root) and target == root) 
            return nullptr;
        //要删除的节点是个叶子
        if(IS_LEAF(target)){
            if(target_parent->left == target) 
                target_parent->left = nullptr;
            else 
                target_parent->right = nullptr;
            return root;
        }
        if(target->right != nullptr){
            auto exchange = findMin(target->right);
            target->val = exchange->val;
            if(exchange == target->right and IS_LEAF(exchange))
                target->right = nullptr;
            else
                deleteNode(target->right, exchange->val);
        }
        else{
            auto exchange = findMax(target->left);
            target->val = exchange->val;
            if(exchange == target->left and IS_LEAF(exchange))
                target->left = nullptr;
            else
                deleteNode(target->left, exchange->val);
        }
        return root;
    }
private:
    TreeNode* findMin(TreeNode* root){
        while(true){
            if(root->left == nullptr)
                return root;
            root = root->left;
        }
    }
    TreeNode* findMax(TreeNode* root){
        while(true){
            if(root->right == nullptr)
                return root;
            root = root->right;
        }
    }
};