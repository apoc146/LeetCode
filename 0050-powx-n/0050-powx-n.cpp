class Solution {
public:
    double fastPow(double x, int n){
        if(n==1){
            return x;
        }
        
        if(n==0){
            return 1;
        }
        
        double half=fastPow(x,n/2);
        if(n%2==0){
            return half*half;
        }
        return half*half*x;
    }
    double myPow(double x, int n) {
        if(n<0){
            x=1.0/x;
            n=abs(n);
        }
        return fastPow(x,n);
    }
};