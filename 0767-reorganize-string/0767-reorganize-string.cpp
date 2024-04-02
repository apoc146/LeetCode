class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> heap;
        
        for(auto& ch:s){
            map[ch]+=1;
        }
        
        for(auto ele:map){
            heap.push(make_pair(ele.second,ele.first));
        }
        
        string ans="";
        while(heap.size()>1){
            auto top1=heap.top();
            heap.pop();
            auto top2=heap.top();
            heap.pop();
            
            ans+=top1.second;
            ans+=top2.second;
            top1.first--;
            top2.first--;
            
            if(top1.first>0){
                heap.push(top1);
            }
            
            if(top2.first>0){
                heap.push(top2);
            }
        }
        
        if(heap.size()==1){
            if(heap.top().first>1){
                return "";
            }else{
                return ans+heap.top().second;
            }
        }
        
        return ans;
    }
};