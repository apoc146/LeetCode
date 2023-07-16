class Solution {
    private:
        bool foo(vector<int> candidates, int target, int idx, int sum, vector<int>& cur, vector<vector<int>>& res){
            
            int n=candidates.size();
            
            if(idx>candidates.size() || sum>target){
                return false;
            }
            
            if(sum==target){
                res.push_back(cur);
            }
            
            
            for(int i=idx;i<n;i++){
                int ele=candidates[i];
                cur.push_back(ele);
                foo(candidates, target, i, sum+ele, cur, res);
                cur.pop_back();
            }
            
            return true;
            
        }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        
        foo(candidates, target, 0, 0, cur, res);
        return res;
        
    }
};