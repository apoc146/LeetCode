class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        def foo(idx):
            if(idx>=n):
                return 0
            if(idx==n-1):
                return nums[idx]
            return max(nums[idx]+foo(idx+2), foo(idx+1))
        
        
        def foo2(nums):
            if(len(nums)<3):
                return max(nums)
            
            dp=[0]*(n+1)
            dp[0]=nums[0]
            dp[1]=max(nums[0],nums[1])
            
            for idx in range(2,n):
                dp[idx]=max(nums[idx]+dp[idx-2],dp[idx-1])
            
            return dp[n-1]
                
        return foo2(nums)