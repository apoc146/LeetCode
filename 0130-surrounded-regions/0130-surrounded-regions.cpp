class Solution {
public:
    int m=-1;
    int n=-1;
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited){
        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]==1 or board[i][j]=='X'){
            return ;
        }
        visited[i][j]=1;
        board[i][j]='T';
        dfs(i,j-1,board,visited);
        dfs(i-1,j,board,visited);
        dfs(i,j+1,board,visited);
        dfs(i+1,j,board,visited);
    }
    
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs(i,0,board,visited);
            dfs(i,n-1,board,visited);
        }
        
        for(int j=0;j<n;j++){
            dfs(0,j,board,visited);
            dfs(m-1,j,board,visited);
        }
        
        for(auto& row:board){
            for(auto& ele:row){
                if(ele=='T'){
                    ele='O';
                }else{
                    ele='X';
                }
            }
        }
    }
};