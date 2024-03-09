class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(1e5);
        vector<int>::iterator it;
        if(nums1[0]<=nums2[0]){
            it=set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
        }else{
            it=set_intersection(nums2.begin(),nums2.end(),nums1.begin(),nums1.end(),ans.begin());
        }
        if(ans.begin()==it){
            return -1;
        }
        return ans.front();
    }
};