class Solution {
public:
    vector<vector<int>> dp;
    int helper(int l, int r, vector<int>& piles){
        if(dp[l][r]) return dp[l][r];
        if(l == r) return piles[l];
        return dp[l][r] = max(piles[l] - helper(l+1,r,piles) , piles[r] - helper(l,r-1,piles));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n+1,vector<int>(n+1,0));
        return helper(0,n-1,piles) > 0;
    }
};