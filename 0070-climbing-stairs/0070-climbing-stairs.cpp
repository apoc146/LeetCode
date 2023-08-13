class Solution {
public:
    int foo(int n){
        vector<int> dp(n+2,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
    
    
//     int foo2(int n){
//         if(n==1){
//             return 1;
//         }
        
//         if(n==2){
//             return 2;
//         }    
    
//         return (foo(n-1)+foo(n-2));
//     }
    
    int climbStairs(int n) {
        int ans=foo(n);
        return ans;
    }
};