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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> retVal;
        if(root==nullptr) return retVal;

        if(root->left != nullptr) {
            std::vector<int> leftTraversal = inorderTraversal(root->left);
            retVal.insert(retVal.end(), leftTraversal.begin(), leftTraversal.end());
        }
        retVal.push_back(root->val);
        if(root->right != nullptr) {
            std::vector<int> rightTraversal = inorderTraversal(root->right);
            retVal.insert(retVal.end(), rightTraversal.begin(), rightTraversal.end());
        }
        
        return retVal;
    }
};