class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /**
        * @brief for an element a,it can be represented as XaY.
        *  Answer is X*Y. X is a prefix and Y is postfix
        */
        
        vector<int> ret(nums.size(),1);
        
        //int mult=nums[i];
        
        ret[0]=1;
        int temp=1;

        for(int i=1;i<ret.size();i++){
            ret[i]=ret[i-1]*nums[i-1];
            // temp*=nums[i-1];
        }

        int postfix=1;
        for(int i=ret.size()-2;i>=0;i--){
            ret[i]*=nums[i+1]*postfix;
            postfix*=nums[i+1];
            // temp*=nums[i-1];
        }
        return ret;
    }
};