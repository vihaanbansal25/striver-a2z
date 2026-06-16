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
class Info {
    public:
    int min, max, sum;
    
    Info(int min, int max, int sum){
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};
class Solution {

public:
    int ans = 0;
    Info maxSum(TreeNode* root){
        if (root == NULL) {
            return Info(INT_MAX, INT_MIN, 0);
        }

        Info left = maxSum(root->left);
        Info right = maxSum(root->right);

        int sum = left.sum + root->val + right.sum;
        if (root->val > left.max && root->val < right.min){
            ans = max(ans, sum);
            return Info(min(root->val, left.min), max(root->val, right.max), sum);
        }
        return Info(INT_MIN, INT_MAX, max(right.sum, left.sum));
    }

    int maxSumBST(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};