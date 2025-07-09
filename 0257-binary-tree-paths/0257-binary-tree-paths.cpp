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
    void paths(TreeNode* root, vector<string>& res, string temp){
        if(!root) return;
        
        if(temp == ""){
            temp += to_string(root->val);
        } else {
            temp += "->" + to_string(root->val);
        }

        if(!root->left && !root->right){
            res.push_back(temp);
            return;
        }

        paths(root->left,res,temp);
        paths(root->right,res,temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        paths(root,res,"");

        return res;
    }
};