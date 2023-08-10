class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        cur=""
        ans=[]
        leftcnt=0
        rightcnt=0

        def dfs(leftcnt, rightcnt, cur, ans):
            if len(cur)==2*n and leftcnt==rightcnt and leftcnt==n:
                ans.append(cur)
                return
            
            if (leftcnt>n):
                return 
            if (rightcnt>leftcnt):
                return
            
            for char in ['(',')']:
                
                cur+=char
                if char=='(':
                    leftcnt+=1
                if char==')':
                    rightcnt+=1
                    
                dfs(leftcnt, rightcnt, cur,ans)
                
                cur = cur[:-1]
                if char=='(':
                    leftcnt-=1
                if char==')':
                    rightcnt-=1
        dfs(leftcnt, rightcnt, cur, ans)
        return ans