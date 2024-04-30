class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        using pii = pair<int, int>;
        
        queue<pii> q;
        int fresh = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        int time = 0;
        vector<int> r_diff = {0, -1, 0, +1};
        vector<int> c_diff = {-1, 0, +1, 0};
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pii node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                
                // BFS
                for(int idx = 0; idx < 4; idx++){
                    int r_idx = x + r_diff[idx];
                    int c_idx = y + c_diff[idx];
                    
                    if(r_idx >= 0 && r_idx < n && c_idx >= 0 && c_idx < m && grid[r_idx][c_idx] == 1){
                        q.push({r_idx, c_idx});
                        grid[r_idx][c_idx] = 2; // Mark as rotten
                        fresh--;
                    }
                }
            }
            if(!q.empty()) time++; // Increment time if there are still rotten oranges
        }
        
        return fresh == 0 ? time : -1;
    }
};
