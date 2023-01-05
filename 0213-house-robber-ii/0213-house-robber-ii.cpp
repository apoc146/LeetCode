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
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp0(n,-1);
        vector<int> dp1(n,-1);

        if(n<4){
            return *max_element(nums.begin(),nums.end());
        }
        
        vector<int> nums0(nums.begin(),nums.begin()+n-1);
        vector<int> nums1(nums.begin()+1,nums.begin()+n);
        
        dp0[0]=max(foo(nums0,0,dp0),foo(nums0,1,dp0));
        dp1[0]=max(foo(nums1,0,dp1),foo(nums1,1,dp1));
    
        int x=dp0[0];
        int y=dp1[0];
        cout<<x<<" "<<y<<endl;
        return max(x,y);
        
        //if first is selected then dont select last
        
    }
};