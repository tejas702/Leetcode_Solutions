class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<array<int,4>> q;
        q.push({0,0,0,k});
        vector<vector<int>> vis(m,vector<int>(n,-1));
        while(!q.empty()){
            array<int,4> c = q.front();
            q.pop();
            int x = c[0], y = c[1];
            if(x<0||y<0||x>=m||y>=n){
                continue;
            }
            if(x == m-1 && y==n-1){
                return c[2];
            }
            if(grid[x][y]==1){
                if(c[3]>0)
                    c[3]-=1;
                else    
                    continue;
            }
            
            if(vis[x][y] >= c[3]){
                continue;
            }
            
            vis[x][y]=c[3];
            
            q.push({x+1,y,c[2]+1,c[3]});
            q.push({x-1,y,c[2]+1,c[3]});
            q.push({x,y+1,c[2]+1,c[3]});
            q.push({x,y-1,c[2]+1,c[3]});
            
        }
        return -1;
    }
};