class Solution {
public:
    string s1="";
    string s2="";
    int n1=-1;
    int n2=-1;
    
    int foo(int idx1, int idx2){
        if(idx1<0){
            return idx2+1;
        }
        if(idx2<0){
            return idx1+1; 
        }
        
        if(s1[idx1]==s2[idx2]){
            return foo(idx1-1,idx2-1);
        }
        //del, insert, replace
        return 1+min(foo(idx1-1,idx2-1), min(foo(idx1-1,idx2),foo(idx1,idx2-1)));
    }
    
    int memo(vector<vector<int>>& dp, int idx1, int idx2){
        
                
        if(idx1<0){
            return idx2+1;
        }
        if(idx2<0){
            return idx1+1; 
        }
        
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }

        
        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]=memo(dp,idx1-1,idx2-1);
        }
        //del, insert, replace
        return dp[idx1][idx2]=(1+min(memo(dp,idx1-1,idx2-1), min(memo(dp,idx1-1,idx2),memo(dp,idx1,idx2-1))));
    }
    
    int minDistance(string word1, string word2) {
        s1=word1;
        s2=word2;
        n1=word1.size();
        n2=word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        // for(int i=0;i<=n1;i++){
        //     dp[i][0]=n1;
        // }
        // for(int j=0;j<=n2;j++){
        //     dp[0][j]=n2;
        // }
        if(n1==0 and n2==0){
            return 0;
        }
        
        if(n1==0){
            return n2;
        }
        if(n2==0){
            return n1;
        }
        memo(dp, n1-1, n2-1);
        return dp[n1-1][n2-1];
    }
};