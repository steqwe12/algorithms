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
    bool isSymmetric(TreeNode* root) {
        if (root->left==nullptr && root->right==nullptr) return true;
        else if(root->left==nullptr || root->right==nullptr) return false;

        //int level=0;
        //TreeNode* curl=root,curr=root;
        std::vector<int> left; // left root right recursivly 
        std::vector<int> right;// right root left recursivly
        TreeNode* leftHead=root->left; 
        TreeNode* rightHead=root->right;

        while(leftHead && rightHead){
            if (leftHead->left==nullptr && rightHead->right!=nullptr) return false;
            else if (leftHead->right==nullptr && rightHead->left!=nullptr) return false;
            else if (leftHead->left!=nullptr && rightHead->right==nullptr) return false;
            else if (leftHead->right!=nullptr && rightHead->left==nullptr) return false;
            //else if (leftHead->left->val!=rightHead->right->val) return false;
            //else if (leftHead->right->val!=rightHead->left->val) return false;
            else if(leftHead->left == nullptr && rightHead->right == nullptr){
                if(leftHead->val!=rightHead->val) return false;
                leftHead = leftHead->right;
                rightHead = rightHead->left;
            }else{
                TreeNode* left = leftHead->left;
                TreeNode* right = rightHead->right;

                while(left->right){
                    left = left->right;
                }
                while(right->left){
                    right = right->left;
                }

                left->right = leftHead;
                leftHead = leftHead->left;
                left->right->left = nullptr;

                right->left = rightHead;
                rightHead = rightHead->right;
                right->left->right = nullptr;
            }
        }
        return true;

    }
};