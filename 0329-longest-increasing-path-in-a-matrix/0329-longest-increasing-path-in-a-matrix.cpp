class Solution {
private:
    int m=-1;
    int n=-1;
    bool check(int x,int y){
        if(x<=-1 or x>=m or y<=-1 or y>=n){
              return false; 
        }
        return true;    
    }
    
public:
    int memo(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(check(x,y) and dp[x][y]!=-1){
            return dp[x][y];
        }
        
        int val=matrix[x][y];
        vector<int> xs={0,-1,0,+1};
        vector<int> ys={-1,0,+1,0};
        m=matrix.size();
        n=matrix[0].size();
        
        int maxVal=1;
        for(int cnt=0;cnt<4;cnt++){
            int ptx=x+xs[cnt];
            int pty=y+ys[cnt];
            if(check(ptx,pty) and matrix[ptx][pty]>val){
                maxVal=max(maxVal,1+memo(ptx,pty,matrix, dp));
                //FML - wasted 3 hours here did 
                // maxVal=1+max(maxVal,foo(ptx,pty,matrix));
            }
        }
        return dp[x][y]=maxVal;
    }
    
        //135/139
    int foo(int x, int y, vector<vector<int>>& matrix){
        int val=matrix[x][y];
        vector<int> xs={0,-1,0,+1};
        vector<int> ys={-1,0,+1,0};
        m=matrix.size();
        n=matrix[0].size();
        
        int maxVal=1;
        for(int cnt=0;cnt<4;cnt++){
            int ptx=x+xs[cnt];
            int pty=y+ys[cnt];
            if(check(ptx,pty) and matrix[ptx][pty]>val){
                maxVal=max(maxVal,1+foo(ptx,pty,matrix));
                //FML - wasted 3 hours here did 
                // maxVal=1+max(maxVal,foo(ptx,pty,matrix));
            }
        }
        return maxVal;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<pair<int,int>> track;
        int ans=1;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<i<<" "<<j<<"\n";
                // ans=max(ans,foo(i,j, matrix));
                ans=max(ans,memo(i,j,matrix,dp));
            }
        }
        return ans;
    }
};