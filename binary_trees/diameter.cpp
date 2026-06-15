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
int height(TreeNode* root,int& d){
    if (root == NULL){
        return 0;
    }
    int lh = height(root->left, d);
    int rh = height(root->right, d);
    d = max(d, lh + rh);

    return 1 + max(lh, rh);
    
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = INT_MIN;
        height(root, d);
        return d;
    }
};