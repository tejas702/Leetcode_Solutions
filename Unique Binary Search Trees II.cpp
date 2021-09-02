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
    
    vector<TreeNode*> dfs(int l, int r){
        vector<TreeNode*> ff;
        if(l > r) return {nullptr};
        if(l == r){
            return {new TreeNode(l)};
        }
        for(int i = l; i <= r; i++){
            vector<TreeNode*> left = dfs(l,i-1);
            vector<TreeNode*> right = dfs(i+1,r);
            for(auto ll : left){
                for(auto rr : right){
                    ff.push_back(new TreeNode(i,ll,rr));
                }
            }     
        }
        return ff;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
};