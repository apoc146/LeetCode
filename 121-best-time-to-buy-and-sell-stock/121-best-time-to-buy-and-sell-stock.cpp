class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        /**
         * @brief l,r = left and right day
         * if +ve gradient, then r++ since we can still find greater peak
         * if -ve gradient , l=r and r++ since we dont want this
         * while doing this keep a track of largest +ve gradient
         * 
         */

        int maxDiff=0; 
        int l=0,r=0;
        while(r<prices.size()){
            //found +ve gradient
            if(prices[r]>=prices[l]){
                maxDiff=max(maxDiff,prices[r]-prices[l]);
                r++;
            }else{
                //found -ve gradient, so skip this
                l=r;
                r++;
            }
        }
        return maxDiff;
        
        /*********** Using a modification of Kadane Algo
         
        int maxProfit(vector<int>& prices){
        // use sort of kadane algorithm 
        int global_min=INT_MAX;
        int global_profit=0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<global_min){
                global_min=prices[i];
            }
            
            //whats the profit at this index
            int local_profit=prices[i]-global_min;
        
            //is this the best profit
            global_profit=max(global_profit,local_profit);
        }
        return global_profit;
        }
        ************/
        
    }
};
