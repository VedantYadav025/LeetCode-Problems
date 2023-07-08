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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int leftIndex = leftLength(root);
        int rightIndex = rightLength(root);
        map<int, map<int, multiset<int>>> data;
        verticalOrderHelper(root, leftIndex - 1,0,  data);
        vector<vector<int>> ans(leftIndex + rightIndex - 1);
        cout << "The Index is " << leftIndex << "\n";
        for (int i = 0; i < ans.size(); i++){
            for (auto j : data[i]){
                for(auto k : j.second){
                    ans[i].push_back(k);
                    std::cout << k << "\n";
                }
            }
        }  
        return ans;
    }
private:
    void verticalOrderHelper(TreeNode* root, int index, int row, map<int, map<int, multiset<int>>> &vector_to_push){
        if (root == nullptr) return;
        vector_to_push[index][row].insert(root->val);
        cout << "Node pushed is " << root->val << " with the index as " << index << " and the row as " << row << "\n";
        if (root->left){
            verticalOrderHelper(root->left, index - 1, row + 1, vector_to_push);
        }
        if (root->right){
            verticalOrderHelper(root->right, index + 1,row + 1, vector_to_push);
        }
    }

int leftLength(TreeNode* root){
    if (root == nullptr) return 0;
    return max(1 + leftLength(root->left), -1 + leftLength(root->right));
}

int rightLength(TreeNode* root){
    if (root == nullptr) return 0;
    return max(-1 + rightLength(root->left), 1 + rightLength(root->right));
}


};