class Solution {
private:
    void dfs(int idx, vector<int>& cur, vector<vector<int>>& ans,int sum,vector<int>& candidates, int target){
        
        int n= candidates.size();
        
        if(sum==target){
            ans.push_back(cur);
            return;
        }    
        
        if(sum>target){
            return ;
        }
        
        for(int i=idx; i<n; i++){
            if(i==idx or candidates[i]!=candidates[i-1]){
                int ele=candidates[i];
                cur.push_back(ele);
                dfs(i+1,cur,ans,sum+ele,candidates,target);
                cur.pop_back();
            }

        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        dfs(0, cur, ans, sum, candidates, target);
        return ans;
    }
};