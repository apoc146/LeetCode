class Solution {
public:
     //use this. sixe==n works only with kahn
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
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto& ele:prerequisites){
            adj[ele[0]].push_back(ele[1]);
        }
        vector<int> ans=topoKahn(adj,n);
        if(ans.size()==n){
            reverse(ans.begin(),ans.end());
            return ans;
        }else{
            return vector<int>(0);
    
        }
    }
};



