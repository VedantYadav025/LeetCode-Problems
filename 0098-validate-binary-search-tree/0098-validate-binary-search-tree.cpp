/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return IsBinarySearchTreeHelper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool IsBinarySearchTreeHelper(TreeNode* root, long int min, long int max){
    if (root == nullptr) return true;
    if (root->val > min && root->val < max){
        return IsBinarySearchTreeHelper(root->left, min, root->val) && IsBinarySearchTreeHelper(root->right, root->val, max);
    }
    else{
        return false;
    }
    }
};