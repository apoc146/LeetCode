class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals.front());
        for(auto& pair:intervals){
            int prev_x=ans.back()[0];
            int prev_y=ans.back()[1];
            int curr_x=pair[0];
            int curr_y=pair[1];
            if(curr_x>prev_y){
                ans.push_back(pair);
            }else{
                if(curr_y<=prev_y){
                    //skip
                    continue;
                }else{
                    vector<int> new_pair(2,0);
                    new_pair[0]=prev_x;
                    new_pair[1]=curr_y;
                    ans.erase(ans.end());
                    ans.push_back(new_pair);
                }
            }
        }
        
        return ans;
    }
};