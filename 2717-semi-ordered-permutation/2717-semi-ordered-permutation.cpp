class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(nums.front()==1 and nums.back()==n){
            return ans;
        }
        
        int idx1=find(nums.begin(),nums.end(),1)-nums.begin();
        int idx2=find(nums.begin(),nums.end(),n)-nums.begin();
        cout<<idx1<<idx2<<endl;
        if(idx1<idx2){
            return idx1+(n-idx2-1);
        }
        
        return idx1+(n-idx2-1)-1;
    }
};