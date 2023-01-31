#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;

        // checks
        if(nums.front()>0){
            return res;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0 && nums[i]==nums[i-1])continue;
            
            // now do two sum
            int target= 0-nums[i];
            
            vector<int> numsT(nums.begin()+i+1,nums.end());
            int j=0;
            int k=numsT.size()-1;
            while(j<k){
                int sum=numsT[j]+numsT[k];
                if(sum==target){
                    vector<int> resT;
                    resT.push_back(nums[i]);
                    resT.push_back(numsT[j]);
                    resT.push_back(numsT[k]);
                    res.push_back(resT);
                    if(numsT[j]==numsT[k]){
                        break;    
                    }
                    j++;
                    k--;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        //Remove Duplicate(via sets) by converting to set -> back to vector
        // set<vector<int>> s(res.begin(),res.end());
        // res.assign(s.begin(),s.end());
        return res;
    }
};