class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //using monotonic stack idea
        stack<pair<int,int>> stk;
        vector<int> mono_vec(nums2.size(),-1);

        vector<int> res(nums1.size(),-1);

        for(int i=0;i<nums2.size();i++){
            int val=nums2[i];
            if(stk.empty()){
                stk.push(make_pair(val,i));
            }else{
                while(!stk.empty() && stk.top().first<val){
                    int ele=stk.top().first;
                    int ele_idx=stk.top().second;
                    stk.pop();

                    mono_vec[ele_idx]=i-ele_idx;
                }
                stk.push(make_pair(val,i));
            }
        }

        for(int i=0;i<nums1.size();i++){
            int nums_ele_idx= distance(nums2.begin(),find(nums2.begin(),nums2.end(),nums1[i]));
            if(mono_vec[nums_ele_idx]>-1){
                res[i]=nums2[nums_ele_idx+mono_vec[nums_ele_idx]]; 
            }
        }

        return res;
    }
};