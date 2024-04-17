class Solution:
    def maxArea(self, height: List[int]) -> int:
        n=len(height)
        l=0
        h=n-1
        mx=0
        while (l<h):
            area=(h-l)*min(height[l],height[h])
            mx=max(area,mx)
            if height[l]<height[h] :
                l+=1
            else:
                h-=1
        return mx