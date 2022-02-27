class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        vector<int> list;
        
        //traverse original matrix
        for(int i=0;i<mat.size();i++){
            for(int j =0;j<mat[i].size();j++){
                list.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int> > ro;
        if(list.size()==r*c){
            
            for(int i=0;i<r;i++){
                vector<int> ri;
                for(int j=0;j<c;j++){
                    ri.push_back(list[i*c+j]);
                }
                ro.push_back(ri);
            }        
        }else{
            return mat;
        }
        return ro;
    }
};