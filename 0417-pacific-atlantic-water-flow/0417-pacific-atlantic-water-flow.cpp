class Solution {
public:
    int m=-1;
    int n=-1;
    void dfs(int i, int j, vector<vector<int>> grid, vector<vector<int>>& visited,int prevVal){
        if( (i<0 or i>=m or j<0 or j>=n) or visited[i][j]==1){
            return;
        }
        
        if(prevVal>grid[i][j]){
            return;
        }
        
        visited[i][j]=1;
        
        if(!(i<0 or i>=m or j-1<0 or j-1>=n) and visited[i][j-1]==0 and grid[i][j-1]>=grid[i][j]){
            dfs(i,j-1,grid,visited,grid[i][j]);
        }
        
        if(!(i-1<0 or i-1>=m or j<0 or j>=n) and visited[i-1][j]==0 and grid[i-1][j]>=grid[i][j]){
            dfs(i-1,j,grid,visited,grid[i][j]);
        }
        
        if(!(i<0 or i>=m or j+1<0 or j+1>=n) and visited[i][j+1]==0 and grid[i][j+1]>=grid[i][j]){
            dfs(i,j+1,grid,visited,grid[i][j]);
        }
        
        if(!(i+1<0 or i+1>=m or j<0 or j>=n) and visited[i+1][j]==0 and grid[i+1][j]>=grid[i][j]){
            dfs(i+1,j,grid,visited,grid[i][j]);
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m=heights.size();
        n=heights[0].size();
        
        vector<vector<int>> pacificVisited(m,vector<int>(n,0));
        vector<vector<int>> atlanticVisited(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            if(pacificVisited[0][j]==0){
                dfs(0,j,heights, pacificVisited, heights[0][j]);
            }
            if(atlanticVisited[m-1][j]==0){
                dfs(m-1,j,heights, atlanticVisited,heights[m-1][j]);
            }
        }

        
        for(int i=0;i<m;i++){
            dfs(i,0,heights, pacificVisited,heights[i][0]);
            dfs(i,n-1,heights, atlanticVisited,heights[i][n-1]);
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificVisited[i][j]==1 and atlanticVisited[i][j]==1){
                    ans.push_back(vector<int>({i,j}));
                }
            }
        }
        return ans;
    }
};