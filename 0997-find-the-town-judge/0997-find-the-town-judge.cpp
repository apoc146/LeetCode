class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    if (n == 1) {
        return 1;
    }
    
    std::vector<int> in_degree(n + 1, 0);
    std::vector<int> out_degree(n + 1, 0);
    
    for (const auto& edge : trust) {
        out_degree[edge[0]]++;  
        in_degree[edge[1]]++; 
    }
    
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == n - 1 && out_degree[i] == 0) {
            return i;
        }
    }
    
    return -1; 
    }
};