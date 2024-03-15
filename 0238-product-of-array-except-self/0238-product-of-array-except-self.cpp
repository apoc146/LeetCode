class Solution {
public:
    void printVec(vector<int> vec){
        for(auto &ele:vec){
            cout<<ele;
        }
        cout<<endl;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> preNum(n,0);
        vector<int> postNum(n,0);
        
        preNum[0]=1;
        for(int i=1;i<n;i++){
            preNum[i]=preNum[i-1]*nums[i-1];
        }
        
        printVec(preNum);
        
        postNum[n-1]=1;
        for(int i=n-2;i>-1;i--){
            postNum[i]=postNum[i+1]*nums[i+1];
        }
        
        printVec(postNum);
        
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=preNum[i]*postNum[i];
        }
        
        return ans;
    }
};