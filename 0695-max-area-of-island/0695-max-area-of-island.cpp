class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> grid, vector<vector<int>>& visited){
        int m=grid.size();
        int n=grid[0].size();
        
        if(r<0 or r>=m or c<0 or c>=n or visited[r][c]==1 or grid[r][c]==0){
            return 0;
        }
        
        visited[r][c]=1;
        int n1=dfs(r,c-1,grid,visited);
        int n2=dfs(r-1,c,grid,visited);
        int n3=dfs(r,c+1,grid,visited);
        int n4=dfs(r+1,c,grid,visited);
        return 1+(n1+n2+n3+n4);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0)); 
        
        int gMax=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                gMax=max(gMax,dfs(i,j,grid,visited));
            }
        }
        return gMax;
    }
};