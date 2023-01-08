class Solution {
public:
    int foo(string s,int idx){
        int n=s.size();
        if(idx>=n){
            return 1;
        }

        int count=0;
        int ones=s[idx]-'0';
        int twos=0;
        if(ones>=1){
            count+=foo(s,idx+1);
        }  

        if(idx<n-1){
            twos=10*ones+s[idx+1]-'0';  
        }

        if(10<=twos && twos<=26){
            count+=foo(s,idx+2);
        }
        return count;
    }


    int fooMemo(string s,int idx,vector<int> dp){
        int n=s.size();
        if(idx>=n){
            return 1;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int count=0;
        int ones=0;
        int twos=0;

        ones=s[idx]-'0';
        twos=10*ones+s[idx+1]-'0';

        if(ones>0){
            count+=fooMemo(s,idx+1,dp);
        }

        if(idx<n-1 && twos>=10 && twos<=26){
            count+=fooMemo(s,idx+2,dp);
        }

        dp[idx]=count;
        return count;
    }

    int fooTab(string s){
        int n=s.size();
        vector<int> dp(n+2,0);

        dp[n]=1;
        dp[n+1]=1;
        for(int i=n-1;i>=0;i--){
            int ones=0;
            int twos=0;
            int count=0;

            ones=s[i]-'0';
            twos=10*ones+s[i+1]-'0';

            count+=(ones>0)?dp[i+1]:0;
            count+=(i<n-1 && twos>=10 && twos<=26)?dp[i+2]:0;

            dp[i]=count;
        }

        return dp[0];
    }


    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0'){
            return 0;
        }

        if(s.size()==1 || s.size()==0){
            return s.size();
        }

        // int ans=foo(s,0);

        //Memoization -Fails
        // vector<int> dp(n+1,-1);
        // int ans=fooMemo(s,0,dp);

        //Tabulation
        int ans=fooTab(s);

        return ans;
    }
};