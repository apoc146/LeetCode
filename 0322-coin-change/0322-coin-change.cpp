class Solution {
public:
    void printVec(vector<int> vec){
        int n=vec.size();
        int i=n;
        while(i-->0){
            cout<<vec[i]<<" ";
        }
    }
    
    int foo2(vector<int> coins,int amount){
        int n=coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int amt =1;amt<=amount;amt++){
            int gmin=amount+1;
            for(int i=0;i<n;i++){
                int coinVal=coins[i];
                int diff=amt-coins[i];
                if(diff>=0){
                    gmin=min(gmin,1+dp[diff]);
                }
            }
            dp[amt]=gmin;
        }
        
        if(dp[amount]==amount+1){
            return -1;
        }
        
        return dp[amount];
    }
    
    int foo(vector<int> coins, int sum, int goal, vector<int> cur, int* gmin){
        
        int n=coins.size();
        
        if(sum==goal){
            //printVec(cur);
            return cur.size();
        }
        
        if(sum>goal){
            return -1;
        }
        
        for(int i=0;i<n;i++){
            if(coins[i]>goal){
                continue;
            }
            cur.push_back(coins[i]);
            int val=foo(coins, sum+coins[i], goal, cur, gmin);
            cur.pop_back();
            if(val!=-1){
                *gmin=min(*gmin, val);
            }
        }
        return *gmin;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cur;
        int gmin = INT_MAX;
        int* ptr = &gmin;
        long int ans=foo2(coins, amount);
        // long int ans = foo(coins, 0, amount, cur, ptr);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        return ans;
    }
};