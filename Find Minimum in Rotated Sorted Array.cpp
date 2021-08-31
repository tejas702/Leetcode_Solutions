class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        if(nums[right] > nums[left]) return nums[left];
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[right]) right=mid;
            else left = mid+1;
        }
        return nums[left];
    }
};