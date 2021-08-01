class Solution {
public:
    int r,c;
    unordered_map<int,int> mp;   
    vector<int> dx = {1,0,0,-1};
    vector<int> dy = {0,1,-1,0};
    int tp = 0,size=0;
    bool isValid(int i, int j){
        return (i>=0&&j>=0&&i<r&&j<c);
    }
    void dfs(vector<vector<int>>& a, int i, int j,int& id,vector<vector<int>>& b,vector<vector<bool>>& vis){
        vis[i][j]=true;
        size+=1;
        b[i][j]=id;
        for(int q=0;q<4;q++){
            int nr = i+dx[q];
            int nc = j+dy[q];
            if(isValid(nr,nc)){
                if(a[nr][nc]==1){
                    if(vis[nr][nc]==false) dfs(a,nr,nc,id,b,vis);
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& a) {
        r=a.size(), c=a[0].size();
        vector<vector<int>> b(r,vector<int>(c,0)); 
        bool ones=false,zeros=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==0)zeros=true;
                else ones=true;
            }
        }
        if(ones == false) return 1;
        if(zeros == false) return (int)(r*c);
        int res = 0;
        
        int id = 2;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                tp=0;size=0;
                if(a[i][j]==1 && vis[i][j]==false){
                    dfs(a,i,j,id,b,vis);
                    mp[id] = size;
                    id += 1;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(b[i][j]==0){
                    set<int> s;
                    for(int q=0;q<4;q++){
                        int nr = i+dx[q];
                        int nc = j+dy[q];
                        if(isValid(nr,nc)){
                            if(b[nr][nc]!=0){
                                s.insert(b[nr][nc]);   
                            }
                        }
                    }
                    int curr = 1;
                    for(auto it : s){
                        curr += mp[it];
                    }
                    res = max(res, curr);
                }
            }
        }
        return res;
    }
};