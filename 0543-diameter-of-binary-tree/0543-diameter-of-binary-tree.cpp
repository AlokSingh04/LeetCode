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
    int diameterCal(TreeNode* root, int& diameter){
        if(!root) return 0;

        int left = diameterCal(root->left,diameter);
        int right = diameterCal(root->right,diameter);

        diameter = max(diameter,left+right);

        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        diameterCal(root,res);

        return res;
    }
};