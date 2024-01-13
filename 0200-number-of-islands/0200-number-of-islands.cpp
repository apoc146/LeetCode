class Solution {
public: 
    bool check(int i,int j, int row, int col){
        if(i<0 or i>=row or j<0 or j>=col){
            return false;
        }
        return true;
    }

void dfs(int i, int j, vector<vector<char>>& graph, vector<vector<int>>& visited) {
    int r = graph.size();
    int col = graph[0].size();

    if (!check(i, j, r, col) or graph[i][j] == '0' or visited[i][j]==1) {
        return ;
    }
    visited[i][j] = 1;
    vector<pair<int, int>> neighs({{0, -1}, {-1, 0}, {0, +1}, {+1, 0}});
    for (int c = 0; c < 4; c++) {
        int xx = i + neighs[c].first;
        int yy = j + neighs[c].second;
        dfs(xx, yy, graph, visited);
    }
}


    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int col = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(r, vector<int>(col, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};