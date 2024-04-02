class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<int> pre(n,1);
        vector<int> post(n,1);
        
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        
        post[n-1]=1;
        for(int j=n-2;j>=0;j--){
            post[j]=post[j+1]*nums[j+1];
        }
        
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*post[i];
        }
        
        return ans;
        
    }
};