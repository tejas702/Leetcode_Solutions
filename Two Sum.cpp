class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i < n; i++){
            if(i>0){
                if(mp.find(target-nums[i])!=mp.end()){
                    return (vector<int>{mp[target-nums[i]],i});
                }
            }
            mp[nums[i]]=i;
        }
        return vector<int>{};
    }
};