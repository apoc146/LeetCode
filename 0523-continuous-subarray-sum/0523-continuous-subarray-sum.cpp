class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum=0;
        int n=nums.size();
        vector<int> prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=(prefixSum[i-1]+nums[i]);
        }
        
        mp[0]=-1;
        for(int i=0;i<n;i++){
            int ele=prefixSum[i];
            if(mp.count(ele%k)>0){
                if(i-mp[ele%k]>=2){
                    return true;
                }
            }else{
                mp[ele%k]=i;
            }
            
        }
        return false;
    }
};