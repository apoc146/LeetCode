class comp{
public:
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p2.second > p1.second){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(auto& ele:nums){
            map[ele]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>,comp> pq;
        for(auto& it:map){
            pq.push(make_pair(it.first,it.second));
        }
        
        while(k>0){
            ans.push_back(pq.top().first);
            pq.pop();
            --k;
        }
        
        return ans;
        
    }
};