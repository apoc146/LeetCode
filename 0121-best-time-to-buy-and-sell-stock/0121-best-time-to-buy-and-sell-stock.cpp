class Solution {
public:
    int max(int x,int y){
        return (x>y)?x:y;
    }
    
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=0;
        int global_max=0;
        
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                global_max=max(global_max,prices[r]-prices[l]);
                r++;
            }else{
                l=r;
                r++;
            }
        }
        
        return global_max;
    }
};