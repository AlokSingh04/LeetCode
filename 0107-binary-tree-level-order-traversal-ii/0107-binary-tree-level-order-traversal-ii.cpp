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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> temp;
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = que.front();
                temp.push_back(curr->val);
                que.pop();

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            res.insert(res.begin(),temp);
        }

        return res;
    }
};