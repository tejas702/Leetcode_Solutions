class Solution {
public:
    int minPatches(vector<int>& nums, int target) {
        int n = nums.size();
        long mx = 0;
        int count = 0;
        for(int x : nums){
            while(x > mx+1){
                mx += (mx+1);
                count += 1;
                if(mx >= target) return count;
            }
            // x <= mx+1
            mx += x;
            if(mx >= target) return count;
        }
        
        while(target > mx){
            mx += (mx+1);
            count += 1;
        }
        
        return count;
    }
};