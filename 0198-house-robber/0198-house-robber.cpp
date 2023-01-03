class Solution {
public:
    int foo(vector<int>& nums,int index, vector<int>& dp){
        // DP Memo
        
        if(index>=nums.size()){
            return 0;
        }
        
        if(index== nums.size()-1){
            dp[index]=nums[index];
            return dp[index];
        }
        
        
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        dp[index]=max(nums[index]+foo(nums,index+2,dp),foo(nums,index+1,dp));
        return dp[index];

        // **** Recursive Solution. **** //
//         if(index>=nums.size()){
//             return 0;
//         }

//         if(index==nums.size()-1){
//             return nums[index];
//         }

//         if(nums.size()<=2){
//             return *max_element(nums.begin(),nums.end());
//         }

//         return max(nums[index]+foo(nums,index+2),foo(nums,index+1));
        
        
        
    }



    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int discard=foo(nums,0,dp);
        cout<<"discard val"<<discard<<endl;
        return dp[0];
    }
};