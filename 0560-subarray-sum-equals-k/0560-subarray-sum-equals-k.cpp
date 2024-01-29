class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int prefix = 0;
        int count = 0;

        // Initialize with a prefix of 0, count = 1
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            // Check if (prefix - k) is in the map
            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            // Update the map with the current prefix
            mp[prefix]++;
        }

        return count;
    }
};
