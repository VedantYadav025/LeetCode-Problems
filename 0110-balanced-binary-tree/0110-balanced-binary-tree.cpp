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
// #include <utility>
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
       return isBalancedHelper(root).second; 
    }
    pair<int, bool> isBalancedHelper(TreeNode* root){
        pair<int, bool> pair;
        if (root == nullptr){
            pair.first = -1;
            pair.second = true;
            return pair;
        }
        if (root->left == nullptr && root->right == nullptr){
           pair.first = 0;
           pair.second = true; 
           return pair;
        }
        std::pair<int,bool> pair_left = isBalancedHelper(root->left);
        std::pair<int,bool> pair_right = isBalancedHelper(root->right);
        pair.first = 1 + max(pair_left.first, pair_right.first);
        pair.second = pair_left.second && pair_right.second && (abs(pair_left.first - pair_right.first) <= 1);
        return pair;
    }
};