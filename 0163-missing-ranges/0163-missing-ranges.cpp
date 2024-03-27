class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i <= n; ++i) {
            long long l = (i == 0) ? lower : (long long)nums[i - 1] + 1;
            long long r = (i == n) ? upper : (long long)nums[i] - 1;
            
            if (l <= r) {
                ans.push_back({(int)l, (int)r});
            }
        }
        
        return ans;
    }
};
