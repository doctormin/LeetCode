#include <vector>
#include <unordered_map>
using namespace std;

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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        int rootVal = preorder[0];
        if(preorder.size() == 1){
            TreeNode* root = new TreeNode(rootVal);
            return root;
        }
        // cout << "source preorder: ";
        // for(auto i : preorder) cout << i << " ";
        // cout << endl << "source inorder: ";
        // for(auto i : inorder) cout << i << " ";
        // cout << endl;
        int rootIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        vector<int> leftTreePre = vector<int>(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        vector<int> leftTreeIn = vector<int>(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightTreePre = vector<int>(preorder.begin() + rootIndex + 1, preorder.end());
        vector<int> rightTreeIn = vector<int>(inorder.begin() + rootIndex + 1, inorder.end());
        // cout << "left preorder: ";
        // for(auto i : leftTreePre) cout << i << " ";
        // cout << endl << "left inorder: ";
        // for(auto i : leftTreeIn) cout << i << " ";
        // cout << endl;
        // cout << "right preorder: ";
        // for(auto i : rightTreePre) cout << i << " ";
        // cout << endl << "right inorder: ";
        // for(auto i : rightTreeIn) cout << i << " ";
        // cout << endl;
        TreeNode* leftTreeRoot = _buildTree(leftTreePre, leftTreeIn);
        TreeNode* rightTreeRoot = _buildTree(rightTreePre, rightTreeIn);
        TreeNode* root = new TreeNode(rootVal, leftTreeRoot, rightTreeRoot);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, inorder);
    }
};