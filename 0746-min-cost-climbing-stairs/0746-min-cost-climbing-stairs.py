class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        if(n<=1):
            return min(cost[0],cost[1])
        
        def foo(idx):
            if(idx==n-1 or idx==n-2):
                return cost[idx]
            return cost[idx]+min(foo(idx+1),foo(idx+2))
        
        def fooDP():
            dp=[0]*(n+1)
            
            dp[0]=cost[0]
            dp[1]=cost[1]
            
            for i in range(2,n):
                dp[i]=cost[i]+min(dp[i-1],dp[i-2])
            
            return min(dp[n-2],dp[n-1])
        
        
        return fooDP()
    
        
    
        