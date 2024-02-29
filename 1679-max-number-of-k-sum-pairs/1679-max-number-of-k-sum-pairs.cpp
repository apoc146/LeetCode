class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int idx=0;
        int ans=0;
        while(idx<nums.size()){
            int a=nums[idx];
            int b=k-a;
            auto it_b=nums.end();
            if(b>=1){
                it_b=find(nums.begin()+idx+1,nums.end(),b);
            }
            if(it_b!=nums.end()){
                ans+=1;
                nums.erase(it_b);
            }
            idx++;
        }
        return ans;
    }
};