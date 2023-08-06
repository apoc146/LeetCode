class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        cur=[]
        ans=[]
        nums = range(1,10)
        sum=0
        
        def dfs(idx, cur, ans, sum):
            if(len(cur)==k and sum==n):
                ans.append(cur.copy())
                return
        
            if(len(cur)>k or sum>n):
                return
            
            for i in range(idx,len(nums)):
                ele=nums[i]
                cur.append(ele)
                dfs(i+1,cur,ans, sum+ele)
                cur.pop()
        
        dfs(0,cur,ans,sum)
        return ans
                