class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=n+1;
            }
        }
        for(int i=0;i<nums.size();i++){
            int num_abs = abs(nums[i]);
            if(num_abs>n){
                continue;
            }
            // make the position negative;
            num_abs--;
            if(nums[num_abs]>0){
                nums[num_abs]*=-1;
            }
        }
            
            for(int i=0;i<nums.size();i++){
                if(nums[i]>0){
                    return i+1;
                }
            }
            
            return n+1;
    }
};