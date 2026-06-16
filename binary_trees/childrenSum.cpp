/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        // Your code goes here
        if (!root->left && !root->right) return true;

        int left = root->left ? root->left->val : 0;
        int right = root->right ? root->right->val : 0;

        if (root->val != left + right) return false;
        bool cl = checkChildrenSum(root->left);
        if (!cl) return false;
        bool cr = checkChildrenSum(root->right);
        if (!cr) return false;
        return true;
    }
};
