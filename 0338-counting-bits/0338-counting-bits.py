class Solution:
    def countBits(self, n: int) -> List[int]:
        dp=[0]*(n+1)
        dp[0]=0
        for i in range(n+1):
            if(i%2==0):
                print(i//2)
                dp[i]=dp[i//2]
            else:
                dp[i]=dp[i//2]+1
        return dp