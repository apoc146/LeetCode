class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
    //KADANE ALGO
    //sum trackers 
    int local=0;
    int global=INT_MIN;
        
        for(auto& val:nums){
            local+=val;
            if(local>global){
                global=local;
            }
            
            //incase we encounter a net -ve sum at a point, no point in including this              sum
            if(local<0){
                local=0;
            }
        }
        return global;
    }
};