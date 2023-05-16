
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> res;
        vector<int> temp(1,1);
        res.push_back(temp);

        for(int i=1;i<n;i++){
            int n=i+1;
            vector<int> vec(n);
            for(int j=0;j<n;j++){
                int l= (j==0)?0:res[i-1][j-1];
                int r= (j==(n-1))?0:res[i-1][j];
                vec[j]=l+r;
            }
            res.push_back(vec);
        }
        return res;
    }
};