class Solution {
public:

    int fooRecr(vector<int>& nums, int index, int prev){
        int n=nums.size();
        if(index==n){
            return 0;
        }

        int val = fooRecr(nums,index+1,prev);
        if(nums[index]>prev){
            val=max(1+fooRecr(nums,index+1,nums[index]),val);
        }
        return val;

    }
    
    
    int fooTab(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n+1,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
        
        
        
    int lengthOfLIS(vector<int>& nums) {
        // return fooRecr(nums,0,INT_MIN);
        return fooTab(nums);
    }
};