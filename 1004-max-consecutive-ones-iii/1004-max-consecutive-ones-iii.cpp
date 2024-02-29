class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<char> numsChar;
        
        int i=0;
        int j=0;
        int zeroCnt=0;
        while(j<n){
            if(nums[j]==0){
                zeroCnt++;
            }
            
            //shrink window if cnt>k
            while(zeroCnt>k){
                i++;
                if(nums[i-1]==0){
                    zeroCnt--;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};