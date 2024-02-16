class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> map;
        for(auto& ele:arr){
            map[ele]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto& it:map){
            vec.push_back(make_pair(it.second,it.first));
        }
        
        //min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap(vec.begin(),vec.end());
        while(k>=0 and heap.top().first<=k){
            k-=heap.top().first;
            heap.pop();
        } 
        
        int ans=0;
        if(!heap.empty() and heap.top().first>k){
            ans+=1;
            heap.pop();
        }
        
        ans+=heap.size();
        return ans;
        
    }
};