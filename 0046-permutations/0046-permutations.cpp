class Solution {

    private:
        void dfs(vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums){
            if(cur.size()==nums.size()){
                //goal reached
                ans.push_back(cur);
                return;
            }
            
            for(auto &ele:nums){
                if(find(cur.begin(),cur.end(),ele)==cur.end()){
                    cur.push_back(ele);
                    dfs(cur,ans,nums);
                    cur.pop_back();
                }
            }
        }    
    
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> cur;
            vector<vector<int>> ans;
            dfs(cur,ans,nums);
            return ans;
        }
};