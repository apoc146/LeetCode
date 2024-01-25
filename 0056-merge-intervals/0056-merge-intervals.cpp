class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals.front());
        int n=intervals.size();
        for(int i=1;i<n;i++){
            auto& curIntr=intervals[i];
            auto& prevIntr=ans.back();
            if(prevIntr[1]<curIntr[0]){
                ans.push_back(curIntr);
            }else{
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],curIntr[1]);
            }
        }
        return ans;
    }
};