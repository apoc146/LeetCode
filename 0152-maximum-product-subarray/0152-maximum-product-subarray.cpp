class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_here=nums[0];
        int min_here=nums[0];
        int global_max=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int ele=nums[i];
            int temp_max_here=max_here;
            max_here=max(ele,max(ele*max_here,ele*min_here));
            min_here=min(ele,min(ele*min_here,ele*temp_max_here));
            global_max=max(global_max,max_here);
        }
        return global_max;
    }
};