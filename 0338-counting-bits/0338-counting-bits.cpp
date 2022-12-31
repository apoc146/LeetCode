class Solution {
public:
    vector<int> countBits(int n) {
        // https://www.youtube.com/watch?v=awxaRgUB4Kw
        //Observe if the number is odd-> dividing by 2(>>1) has 1 less bit
        // if number if even then dividing by 2 doesnt change the number of set bits
        // odd has 1 in its LSB and even has 0
        
        vector<int> dp(n+1,0);
        
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            if(i%2==0){
                //even
                dp[i]=dp[i/2];
            }else{
                dp[i]=dp[i/2]+1;
            }
        }
        return dp;
    }
};