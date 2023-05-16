class Solution {
public:
    int fib(int n) {
        
        //memoiszation approach
//         static vector<int> dp(n+1,-1);
//         dp[0]=0;
//         dp[1]=1;

//         if(dp[n]!=-1){
//             return dp[n];
//         }

//         if(n>1){
//             dp[n]=fib(n-1)+fib(n-2);
//         }

//         return dp[n];
        
        
        //tabular approach 
    vector<int> dp(n+1,0);
    
    if(n==0 || n==1){
        return n;
    }

    dp[0]=0;
    dp[1]=1;
    
   
    
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    return dp[n];
    }
};