class Solution {
private:
    priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++){
            this->pq.push(stones[i]);
        }
        
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            if(x==y){
                pq.pop();
            }else{
                pq.pop();
                pq.push(y-x);
            }
        }
        
        if(pq.size()==0){
            return 0;
        }else{
            return pq.top();
        }
        
    }
};