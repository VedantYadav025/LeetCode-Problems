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
    int diameterOfBinaryTree(TreeNode* root) {
       if (root == nullptr) return -1;
       if (root->left == nullptr && root->right == nullptr) return 0;

       return max(2 + heightTree(root->left) + heightTree(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right))); 
    }

private:
    int heightTree(TreeNode* root){
        if (root == nullptr) return -1;
        return 1 + max(heightTree(root->left), heightTree(root->right));
    }
};