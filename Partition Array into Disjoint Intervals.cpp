class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxl(n),minr(n);
        int maxll=-1;
        for(int i=0;i<n;i++){
            maxll=max(maxll,nums[i]);
            maxl[i]=maxll;
        }
        int minrr = INT_MAX;
        for(int i=n-1;i>=0;i--){
            minrr=min(minrr,nums[i]);
            minr[i]=minrr;
        }
        for(int i=0;i+1<n;i++){
            if(maxl[i]<=minr[i+1]){
                return (i+1);
            }
        }
        return -1;
    }
};