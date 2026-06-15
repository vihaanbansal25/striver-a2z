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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p == NULL) return q == NULL;
        if (q == NULL) return p == NULL;
        
        if (p->val != q->val) return false;

        bool cl = isSameTree(p->left, q->right);
        if (!cl) return false;
        bool cr = isSameTree(p->right, q->left);
        if (!cr) return false;

        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSameTree(root->left, root->right);
    }
};