class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        unordered_map<int,int> map;
        for(auto ele:nums){
            map[ele]+=1;
        }
        
        int global=INT_MIN;
        for(auto ele:nums){
            //check for start of seq
            if(map.count(ele-1)==0){
                int len=1;
                int succ=ele+1;
                while(map.count(succ)){
                    len++;
                    succ++;
                }
                global=max(global,len);
            }else{
                //skip
            }
        }
        return global;
    }
};