class Solution {
public:
    bool check(int r, int c, vector<vector<int>> grid){
        int n=grid.size();
        int m=grid[0].size();
        
        if(r>=0 and r<n and c>=0 and c<m){
            return true;
        }
        
        return false;
    }
    
    int dfs(int r, int c, vector<vector<int>>& visited, vector<vector<int>> grid){
        if( check(r,c,grid)==false or visited[r][c]==1 or grid[r][c]==0){
            return 0;
        }

        visited[r][c]=1;
        int ans=1;
        ans+=dfs(r-1,c,visited, grid);
        ans+=dfs(r,c-1,visited, grid);
        ans+=dfs(r+1,c,visited, grid);
        ans+=dfs(r,c+1,visited, grid);
        
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 and grid[i][j]==1){
                    mx=max(mx,dfs(i,j,visited, grid));  
                }
            }
        }
        
        return mx;
    }
};