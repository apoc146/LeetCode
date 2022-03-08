class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        long int global_area=0;
        while(l<r){
            long int area=(r-l)*min(height[l],height[r]);
            global_area=max(area,global_area);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return global_area;
    }
};