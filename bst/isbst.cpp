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
private:
    bool isValid(TreeNode* root, long lower, long higher){
        if (root == NULL) return true;
        
        if (root->val > lower && root->val < higher){
            bool cl = isValid(root->left, lower, root->val);
            if (!cl) return false;
            bool cr = isValid(root->right, root->val, higher);
            if (!cr) return false;
            return true;
        } else {
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};