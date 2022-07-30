class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
                
        //(key,val)
        unordered_map<int,int> m1;
        unordered_map<int,int>::iterator it;
        
        //m2 is reverse of m1
        //(val,key)
        multiset<int,int> m2;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        
        vector<pair<int,int>> heap;
        for(it=m1.begin();it!=m1.end();it++){
            heap.push_back(make_pair(it->second,it->first));
        }
        
        make_heap(heap.begin(),heap.end());
        
        vector<int> res;
        
        for(int i=0;i<k;i++){
            res.push_back(heap.front().second);
            pop_heap(heap.begin(),heap.end());
            heap.pop_back();
        }
        
        return res;
        
    }
};