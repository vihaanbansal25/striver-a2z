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
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dis = 0;
        while (!q.empty()){
            int size = q.size();
            if (dis == k) break;
            dis++;
            while (size--){
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            } 
        }

        vector<int> res;
        while (!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};