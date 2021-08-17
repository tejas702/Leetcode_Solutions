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
    int res = 0;
    void helper(TreeNode* root, int maxi){
        if(root==NULL)return;
        if(root->val >= maxi) res+=1;
        helper(root->left,max(maxi,root->val));
        helper(root->right,max(maxi,root->val));
    }
    
    int goodNodes(TreeNode* root) {
        helper(root,root->val);
        return res;
    }
};