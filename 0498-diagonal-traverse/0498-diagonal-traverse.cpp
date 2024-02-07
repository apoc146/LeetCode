class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // diag sum:eles
        map<int,vector<int>> map;
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int diagSum=i+j;
                map[diagSum].push_back(mat[i][j]);
            }
        }
        
        bool flag=false;
        vector<int> res;
        for(auto& it:map){
            vector<int> vec;
            vec=it.second;
            if(!flag){
                reverse(vec.begin(),vec.end()); 
            }
            for(auto& ele:vec){
                res.push_back(ele);
            }
            flag=!flag;
        }
        return res;
    }
};