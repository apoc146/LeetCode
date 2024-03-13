class Solution {
public:
    map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            this->mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int sz=this->mp[target].size();
        return this->mp[target][rand()%sz];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */