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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()){
            long long n = q.size();
            long long li = INT_MAX, ri = INT_MIN;
            while (n--){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long idx = p.second;
                li = min(li, idx);
                ri = max(ri, idx);

                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }
            maxi = max(maxi, ri - li + 1);
        }
        return maxi;
    }
};