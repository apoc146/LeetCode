// class Solution {
// public:
//     int getProd(vector<int> vec, int i, int j){
//         int ans=1;
//         vector<int> temp(vec.begin()+i,vec.begin()+j+1);
//         for(auto& ele:temp){
//             ans*=ele;
//         }
//         return ans;
//     }
    
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n=nums.size();
//         int i=0;
//         int j=0;
//         int cnt=0;
//         while(j<n and i<=j){
//             int prod=getProd(nums,i,j);
//             if(prod<k){
//                 cnt++;
//                 j++;
//             }else{
//                 i++;
//             }
            
//             if(i>j){
//                 j=i;
//             }
            
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int getProd(vector<int>& vec, int i, int j) {
        int ans = 1;
        for (int k = i; k <= j; ++k) {
            ans *= vec[k];
        }
        return ans;
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (j < n) {
            int prod = getProd(nums, i, j);
            if (prod < k) {
                cnt += (j - i + 1); 
                j++;
            } else {
                i++; 
                if (i > j) {
                    j = i; 
                }
            }
        }
        return cnt;
    }
};
