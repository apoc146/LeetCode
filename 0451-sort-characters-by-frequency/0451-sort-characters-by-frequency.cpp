class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(auto ch:s){
            map[ch]+=1;
        }
        
        priority_queue<pair<int,char>> heap;
        
        for(auto ele:map){
            heap.push(make_pair(ele.second,ele.first));    
        }
        
        string ans="";
        
        cout<<heap.size();
        
        while(heap.size()>0){
            auto ele = heap.top();
            ans+=string(ele.first, ele.second);
            heap.pop();

        }
        
        return ans;
        
    }
};