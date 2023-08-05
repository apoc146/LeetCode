class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        cur=[]
        ans=[]
        sum=0
        n=len(candidates)
        def dfs(idx, cur, ans, sum):
            if(sum==target):
                ans.append(cur.copy())
                return 
            if(sum>=target):
                return;
        
            for i in range(idx,n):
                ele=candidates[i]
                cur.append(ele)
                dfs(i, cur, ans, sum+ele)
                cur.pop()
        dfs(0,cur,ans, sum)
        return ans