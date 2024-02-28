class Solution {
public:
    // eventually its diff btw two numbers
    // to min (a-b) for all a, I need to find closest b
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=1;i<nums.size();i++){
            ans=min(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};