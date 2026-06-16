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
        vector<int> inorder;
        TreeNode* node = root;
        while (node != NULL){
            if (node->left == NULL){
                inorder.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* rightmost = node->left;
                while (rightmost->right && rightmost->right != node){
                    rightmost = rightmost->right;
                }

                if (rightmost->right == NULL){
                    rightmost->right = node;
                    node = node->left;
                } else{
                    rightmost->right = NULL;
                    inorder.push_back(node->val);
                    node = node->right;
                }
            }
        }
        return inorder;
    }
};