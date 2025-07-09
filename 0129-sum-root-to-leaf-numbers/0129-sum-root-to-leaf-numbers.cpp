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
    void sumNo(TreeNode* root, int& sum, int temp){
        if(!root) return;

        temp = temp*10+root->val;

        if(!root->left && !root->right){
            sum += temp;
            return;
        }

        sumNo(root->left,sum,temp);
        sumNo(root->right,sum,temp);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        
        sumNo(root,sum,0);

        return sum;
    }
};