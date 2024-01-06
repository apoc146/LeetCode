class Solution {
public:
    int n1=-1;
    int n2=-1;
    void print2DVector(const std::vector<std::vector<int>>& matrix) {
        for (const auto& row : matrix) {
            for (const int& element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }
    
    bool foo(int idx1, int idx2, string s1, string s2, string s3){
        if(idx1 == n1 and idx2==n2){
            return true;
        }
        bool ans=false;
        if(idx1< n1 and s1[idx1]==s3[idx1+idx2]){
            ans |= foo(idx1+1,idx2, s1,s2,s3);
        }
        if(idx2< n2 and s2[idx2]==s3[idx1+idx2]){
            ans |= foo(idx1,idx2+1,s1,s2,s3);
        }
        return ans;
    }
    bool memo(vector<vector<int>>& dp,int idx1, int idx2, string s1, string s2, string s3){
        
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(idx1==n1 and idx2==n2){
            return dp[idx1][idx2]=1;
        }
        
        bool ans=false;
        if(idx1< n1 and s1[idx1]==s3[idx1+idx2]){
            ans |= memo(dp,idx1+1,idx2, s1,s2,s3);
        }
        if(idx2< n2 and s2[idx2]==s3[idx1+idx2]){
            ans |= memo(dp,idx1,idx2+1,s1,s2,s3);
        }
        return dp[idx1][idx2]=ans;    
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size();
        n2=s2.size();
        int n3=s3.size();
        
        if(n1+n2 != n3){
            return false;
        }
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        // return foo(0,0, s1, s2, s3);
        memo(dp,0,0,s1,s2,s3);
        return dp[0][0];
    }
};