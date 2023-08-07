class Solution:
    def partition(self, s: str) -> List[List[str]]:
        cur=[]
        ans=[]
        idx=0;
        n=len(s)
        
        def dfs(idx,cur,ans):
            if (idx>=n):
                ans.append(cur.copy())
                return;
            for j in range(idx,n):
                ele=s[idx:j+1]
                if(ele==ele[::-1]):
                    cur.append(ele)
                    dfs(j+1,cur,ans)
                    cur.pop()
        dfs(0,cur,ans)
        return ans
        