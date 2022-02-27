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
    }
};