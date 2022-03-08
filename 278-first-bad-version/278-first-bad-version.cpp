// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int binary(int a,int b,int n){
        
        int mid=a+(b-a)/2;
        if(isBadVersion(mid)==true){
            
            //1st element
            if(mid==1){
                return 1;
            }
            
            //last element
            if(mid==n && isBadVersion(n-1)==false){
                 return n;
            }
            
            //mid element 
            if(isBadVersion(mid-1)==false && isBadVersion(mid+1)==true){
                return mid;
            }
            
            // for FTT(mid)TT
            return binary(a,mid-1,n);
        }
        
        return binary(mid+1,b,n);
    }
    
    int firstBadVersion(int n) {
        return binary(1,n,n);
    }
};