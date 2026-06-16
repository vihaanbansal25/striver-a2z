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
    TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start){
        TreeNode* target;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start) target = node; 

            if (node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return target;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = markParents(root, parent, start);

        int time = 0;
        unordered_map<TreeNode*, bool> infected;
        infected[target] = true;
        queue<TreeNode*> q;
        q.push(target);

        while(!q.empty()){
            int size = q.size();
            time++;
            while (size--){
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !infected[node->left]){
                    q.push(node->left);
                    infected[node->left] = true;
                }
                if (node->right && !infected[node->right]){
                    q.push(node->right);
                    infected[node->right] = true;
                }
                if (parent[node] && !infected[parent[node]]){
                    q.push(parent[node]);
                    infected[parent[node]] = true;
                }
            }
        }
        return time - 1;
    }
};