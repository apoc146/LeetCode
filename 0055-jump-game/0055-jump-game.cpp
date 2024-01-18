class Solution {
public:
    bool foo(int idx, vector<int> nums, vector<int>& memo){
        
        if(idx>=nums.size()-1){
            return memo[memo.size()-1]=true;
        }
        
        if(memo[idx]!=-1){
            return memo[idx];
        }
        
        bool ans=false;
        
        for(int jmpSize=1;jmpSize<=nums[idx];jmpSize++){
            ans|=foo(idx+jmpSize,nums,memo);
            if(ans==true){
                break;
            }
        }
        return memo[idx]=ans;
    }
    bool canJump(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> memo(n,-1);
        // return foo(0,nums,memo);
        int n=nums.size();
        int goalPos=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=goalPos){
                goalPos=i;
            } 
        }
        if(goalPos==0){
            return true;
        }
        return false;
    }
};