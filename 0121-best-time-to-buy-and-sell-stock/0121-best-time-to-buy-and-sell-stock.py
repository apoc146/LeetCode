class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l=0
        h=0
        n=len(prices)
        mx=0
        while(h<n):
            mx=max(mx,prices[h]-prices[l])
            if (prices[h]>=prices[l]):
                h+=1
            else:
                l=h
                h+=1
        return mx
            