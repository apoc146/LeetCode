class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        maxIdx=0
        maxLen=1
        n=len(s)
                
            
        def expandSearch(i,j):
            while (i>=0 and j<n and s[i]==s[j]):
                i-=1
                j+=1
            return (j-i+1-2,i+1)
    
        for idx in range(n):
            l1,s1=expandSearch(idx,idx)
            l2,s2=expandSearch(idx,idx+1)
            maxLen=max(maxLen,l1,l2)
            if(maxLen==l1):
                maxIdx=s1
            elif (maxLen==l2):
                maxIdx=s2
                
        return s[maxIdx:maxIdx+maxLen]