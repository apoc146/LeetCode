class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // write merge function of mergeSort
        int i=0;
        int j=0;
        int k=0;
        vector<int> ret(m+n);
        
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ret[k]=nums1[i];
                k++;
                i++;
            }else{
                ret[k]=nums2[j];
                k++;
                j++;
            }
        }
            
            while(i<m){
                ret[k]=nums1[i];
                k++;
                i++;
            }
            
            while(j<n){
                ret[k]=nums2[j];
                k++;
                j++;
            }
            
            nums1.assign(ret.begin(),ret.end());
    }
};