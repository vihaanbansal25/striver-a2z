/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
// private:
//     TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
//         if (root == NULL) return NULL;
//         if (root == p || root == q) return root;

        
//     }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        if ((p->val <= val && q->val >= val) || (p->val >= val && q->val <= val)){
            return root;
        } else if (p->val < val && q->val < val){
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};