class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        using pii= pair<int,int>;
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        int fresh =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        int time=0;
        while(q.size()>0 and fresh>0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                
                pii node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                
                visited[x][y]=1;
                vector<int> r_diff={0,-1,0,+1};
                vector<int> c_diff={-1,0,+1,0};
                
                //bfs
                for(int idx=0;idx<4;idx++){
                    int r_idx=x+r_diff[idx];
                    int c_idx=y+c_diff[idx];
                    
                    if(r_idx >=0 and r_idx<n and c_idx>=0 and c_idx<m and visited[r_idx][c_idx]==0 and grid[r_idx][c_idx]==1){
                        q.push({r_idx,c_idx});
                        visited[r_idx][c_idx]=1;
                        grid[r_idx][c_idx]=2;
                        fresh--;
                    }
                }
                
            }
            time++;
        }
        return fresh == 0 ? time : -1; // Return -1 if there are still fresh oranges
    }
};