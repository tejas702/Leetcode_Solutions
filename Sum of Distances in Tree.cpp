class Solution {
public:
    
    vector<vector<int>> adj;
    vector<int> subans,count;
    vector<int> ans;
    void dfs1(int src, int par){
        int numnodes = 1;
        int dist = 0;
        for(auto it : adj[src]){
            if(it != par){
                dfs1(it,src);
                numnodes += count[it];// number of nodes in child subtree
                dist += subans[it]+count[it];// number of nodes + distances of child subtree
            }
        }
        subans[src] = dist;
        count[src] = numnodes;
    }
    
    void dfs2(int src, int par, int& n){
        if(par == -1){
            ans[src] = subans[src]+(n-count[src]);
        }else{
            ans[src] = subans[src] + (n-count[src])+(ans[par]-(subans[src]+count[src]));
        }
        for(auto it : adj[src]){
            if(it != par){
                dfs2(it,src,n);
            }
        }
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        subans.resize(n+1,0);count.resize(n+1,0);
        dfs1(0,-1);
        ans.resize(n,0);
        dfs2(0,-1,n);
        return ans;        
    }
};