class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        cur=[]
        ans=[]
        nums=range(1,n+1)
        
        def dfs(idx, cur, ans, k):
            if (k==0):
                ans.append(cur.copy())
                return
            
            
            for i in range(idx,len(nums)):
                cur.append(nums[i])
                k=k-1
                dfs(i+1, cur, ans, k)
                k=k+1
                cur.pop()
        dfs(0,cur,ans,k)
        return ans
        