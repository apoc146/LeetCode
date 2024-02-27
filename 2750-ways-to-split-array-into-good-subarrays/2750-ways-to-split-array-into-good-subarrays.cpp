class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int MOD=int(1e9+7);
        int ones=accumulate(nums.begin(),nums.end(),0);
        cout<<ones;
        int sticks=ones-1;
        if(ones<=1){
            return ones;
        }
        
        long long ans=1;
        auto it1=find(nums.begin(),nums.end(),1);
        auto it2=find(it1+1,nums.end(),1);
        while(it2!=nums.end()){
            int zeroes=it2-it1;
            ans*=zeroes;
            ans%=MOD;
            it1=it2;
            it2=find(it1+1,nums.end(),1);
        }
        return ans% MOD;
    }
};