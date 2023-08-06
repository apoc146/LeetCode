class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        cur=[]
        ans=[]
        n=len(nums)
        def dfs(idx, cur, ans):
            ans.append(cur.copy());
            for i in range(idx,n):
                ele=nums[i]
                cur.append(ele)
                dfs(i+1,cur,ans)
                cur.pop()
        dfs(0,cur,ans)
        return ans
            
        