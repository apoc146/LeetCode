class Solution {
public:
    
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> first_oc;
        first_oc[0]=0;
        int len=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count-=1;
            }else{
                count+=1;
            }
            
            if(first_oc.find(count)!=first_oc.end()){
                len=max(len,i+1-first_oc[count]);
            }else{
                first_oc[count]=i+1;
            }
        }
        return len;
    }
};
