// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int binary(int a,int b,int n){
        int mid=a+(b-a)/2;
        if(isBadVersion(mid)==true){
            if(mid==1){
                return 1;
            }
            if(mid==n && isBadVersion(n-1)==false){
                 return n;
            }
            if(isBadVersion(mid-1)==false && isBadVersion(mid+1)==true){
                return mid;
            }
            return binary(a,mid-1,n);
        }
        return binary(mid+1,b,n);
    }
    
    int firstBadVersion(int n) {
        return binary(1,n,n);
    }
};