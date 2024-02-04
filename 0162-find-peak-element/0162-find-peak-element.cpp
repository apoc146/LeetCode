class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return n-1;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        
        int l=1;
        int r=n-2;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] >nums[mid-1] and nums[mid]>nums[mid+1]){
                return mid;
            } 
            
            if(nums[l]>nums[mid]){
                r--;
            }else{
                l++;
            }
        }
        return -1;
    }
};