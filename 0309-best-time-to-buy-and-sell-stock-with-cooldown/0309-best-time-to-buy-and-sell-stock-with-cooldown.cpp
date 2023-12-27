class Solution {
public:
    int n=-1;
    vector<int> costs;
    //at idx we are in buying state.
    // means last state was sell or coldown
    // fn - profit from [idx...n]
    int foo(int idx, bool buying){

        if(idx>=n){
            return 0;
        }
        int profit=0;
        if(buying==true){
            int buyVal=foo(idx+1, false)-costs[idx];
            int cooldownVal=foo(idx+1, true); 
            return max(buyVal,cooldownVal);
        }else{
            int sellVal=foo(idx+2, true)+ costs[idx];
            //wait to sell
            int cooldownVal=foo(idx+1, false);
            return max(sellVal, cooldownVal);
        }
        return -1;
    }
    
    int memo(vector<vector<int>>& dp, int idx, bool buying){
        int state=(buying==true)?0:1;
        if(idx>=n){
            return 0;
        }

        //could go wrong as val can go -1 during recr
        if(dp[idx][state]!=-1){
            return dp[idx][state];
        }

        int profit=0;
        if(buying==true){
            int buyVal=memo(dp,idx+1, false)-costs[idx];
            int cooldownVal=memo(dp,idx+1, true); 
            return dp[idx][state] = max(buyVal,cooldownVal);
        }else{
            int sellVal=memo(dp,idx+2, true)+ costs[idx];
            //wait to sell
            int cooldownVal=memo(dp,idx+1, false);
            return dp[idx][state]=max(sellVal, cooldownVal);
        }
        return -1;
    }
    
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2, -1));
        costs=prices;
        return memo(dp,0,true);
    }
};