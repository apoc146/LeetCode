class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> nums3(1e5,0);
        auto it=set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        nums3.resize(it-nums3.begin());
        it=unique(nums3.begin(), nums3.end());
        nums3.resize(it-nums3.begin());
        return nums3;
    }
};