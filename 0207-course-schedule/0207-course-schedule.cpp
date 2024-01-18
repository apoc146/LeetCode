class Solution {
public:
    //dfs with topo
    void dfs(int idx, vector<int> adj[], vector<int>& visited, stack<int>& st){
        if(visited[idx]==1){
            return ;
        }
        visited[idx]=1;
        for(auto& ele:adj[idx]){
            dfs(ele,adj,visited,st);
        }
        st.push(idx);
    }
    
    //return topo sort
    vector<int> topoDFS(vector<int> adj[], int n){
        vector<int> visited(n,0);
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            dfs(i, adj, visited, st);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    
    vector<int> topoKahn(vector<int> adj[], int n){
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                int ele=adj[i][j];
                indegree[ele]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto& neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }   
        return ans;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto& ele:prerequisites){
            adj[ele[0]].push_back(ele[1]);
        }
        return (topoKahn(adj,n).size()==n);
    }
};