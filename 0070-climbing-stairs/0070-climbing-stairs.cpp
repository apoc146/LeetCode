class Solution {
public:
    int climbStairs(int n) {
    // //Recursive solution 
    //     if(n==1){
    //         return 1;
    //     } 
    //     if(n==2){
    //         return 2;
    //     }
    //     if(n<1){
    //         return 0;
    //     }
    //     return climbStairs(n-1)+climbStairs(n-2);
    // }
        
        if(n<3){
            return n;
        }
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};