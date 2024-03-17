class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int n=nums.size();
        
        int mx=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==1?1:-1);
            if(mp.count(sum)>0){
                mx=max(mx,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return mx;
    }
};