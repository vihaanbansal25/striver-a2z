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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        TreeNode* root = build(preorder, idx, INT_MAX);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int& idx, int ub){
        if (idx >= preorder.size() || preorder[idx] > ub) return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = build(preorder, idx, root->val);
        root->right = build(preorder, idx, ub);
        return root;
    }
};