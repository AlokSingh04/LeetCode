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
    void path(TreeNode* root, int& targetSum, vector<vector<int>>& res, vector<int> temp, int sum){
        if(!root) return;

        sum+=root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right && sum == targetSum){
            res.push_back(temp);
        }

        path(root->left,targetSum,res,temp,sum);
        path(root->right,targetSum,res,temp,sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;

        path(root,targetSum,res,{},0);

        return res;
    }
};