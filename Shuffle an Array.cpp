class Solution {
public:
    vector<int> a,ff;
    Solution(vector<int>& nums) {
        a=nums;ff=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        a=ff;
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        a=ff;
        for(int i=0;i<a.size();i++){
            int rr = (rand()%a.size());
            swap(a[i],a[rr]);
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */