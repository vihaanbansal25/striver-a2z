/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
  public:
    vector <int> bottomView(TreeNode *root){
    	//your code goes here
        queue<pair<TreeNode*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int line = p.second;

            mpp[line] = node->data;
            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        vector<int> ans;
        for (auto p : mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};