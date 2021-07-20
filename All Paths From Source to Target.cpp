class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<bool> vis,vector<vector<int>>& vc,vector<int> tt,int S){
        if(vis[S]==true)return;
        vis[S]=true;
        for(auto it : graph[S]){
            if(vis[it]==false){
                tt.push_back(it);
                dfs(graph,vis,vc,tt,it);
                tt.pop_back();
            }
        }
        if(S==(graph.size() - 1)){
            vc.push_back(tt);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> vc;
        vector<int> tt;
        tt.push_back(0);
        vector<bool> vis(graph.size() + 5, false);
        dfs(graph,vis,vc,tt,0);
        return vc;
    }
};