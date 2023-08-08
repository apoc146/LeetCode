class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mp={"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
        cur=""
        ans=[]
        n=len(digits)
        
        def dfs(idx, cur, ans):            
            if(len(cur)==len(digits)):
                ans.append(cur)
                return 
            
            for char in mp[digits[idx]]:
                cur+=char
                dfs(idx+1, cur, ans)
                cur=cur[:-1]    
        if(digits==""):
            return []
        dfs(0,cur,ans)
        return ans
            
            