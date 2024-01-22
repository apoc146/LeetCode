class Solution {
public:
    int foo(int n){
        string nStr=to_string(n);
        int sum=0;
        for(auto& digit:nStr){
            sum+=pow((digit-'0'),2);
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        int slow=n;
        int fast=foo(foo(n));
        while(slow!=fast){
            slow=foo(slow);
            fast=foo(foo(fast));
        }
        
        if(slow==1){
            return true;
        }
        return false;
        
    }
};