class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //---WAY 1
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;
        
        
        //WAY 2 slower
//         unordered_map<int,int> map;
//         for(int i=0;i<nums.size();i++){
//             map[nums[i]]++;
//         }
        
//         for(auto it=map.begin();it!=map.end();it++){
//             if(it->second > 1){
//                 return it->first;
//             }
//         }
        
//         return -1;
        
        //WAY -3
        //MODIFIED COUNTING SORT
       vector<int> v(nums.size()+1,0);
        // memset(v,0,sizeof(v));
        for(auto i:nums){
            v[i]++;
        }
        
        int count=0;
        for(auto j:v){
            if(j>1){
                return count;
            }
            count++;
        }
        
        return -1;  
        
    }
};