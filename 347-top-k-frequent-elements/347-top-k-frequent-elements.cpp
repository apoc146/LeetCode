class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            
        unordered_map<int,int> m1;
        unordered_map<int,int>::iterator it;

        //make map of key,count
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        
        //vector of pair(count,key)
        //cant use maps since count can be same, maps need unique keys
        vector<pair<int,int>> heap;
        
        for(it=m1.begin();it!=m1.end();it++){
            heap.push_back(make_pair(it->second,it->first));
        }
        
        //make heap of above vector
        make_heap(heap.begin(),heap.end());
        
        vector<int> res;
        
        //pop heap K times
        for(int i=0;i<k;i++){
            res.push_back(heap.front().second);
            pop_heap(heap.begin(),heap.end());
            heap.pop_back();
        }
        
        //Ans
        return res;
        
    }
};