/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return {};
        queue<pair<Node*,int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        while(!q.empty()){
            pair<Node*,int> curr = q.front();
            q.pop();
            if(curr.second==(int)ans.size()){
                ans.emplace_back();
            }
            ans[curr.second].push_back((curr.first)->val);
            vector<Node*> next = (curr.first)->children;
            for(auto it : next){
                    q.push({it,curr.second+1});
            }
        }
        return ans;
        
    }
};