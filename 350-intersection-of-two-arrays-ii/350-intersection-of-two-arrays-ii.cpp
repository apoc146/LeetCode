class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
unordered_map<int,int >map;
        unordered_map<int,int >::iterator it;
        int l1=nums1.size();
        int l2=nums2.size();
        vector<int> res;
        if(l1>l2){
            for(int i=0;i<nums1.size();i++){
                map[nums1[i]]++;
            }
            
            for(int i=0;i<nums2.size();i++){
                if(map.count(nums2[i]) && map[nums2[i]]!=0){
                    res.push_back(nums2[i]);
                    map[nums2[i]]--;
                    // res.insert(res.end(),nums2[i],map[nums2[i]]);
                }
            }
        }else{
             for(int i=0;i<nums2.size();i++){
                map[nums2[i]]=map[nums2[i]]+1;
            }
            
            for(int i=0;i<nums1.size();i++){
                if(map.count(nums1[i]) && map[nums1[i]]!=0){
                    res.push_back(nums1[i]);
                    map[nums1[i]]--;
                }
            }
        }
        return res;
        }
};