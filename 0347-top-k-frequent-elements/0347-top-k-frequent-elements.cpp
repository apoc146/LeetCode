class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto ele:nums){
            map[ele]+=1;
        }
        
        priority_queue<pair<int,int>> heap;
        for(auto ele:map){
            heap.push(make_pair(ele.second,ele.first));
        }
        
        vector<int> ans;
        while(k-->0){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};