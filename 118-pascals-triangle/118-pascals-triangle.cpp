class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        vector<int> t;
        t.push_back(1);
        ret.push_back(t);
        for (size_t i = 1; i < numRows; i++)
        {
            /* code */
            vector<int> v;
            v.push_back(1);
            for (size_t j = 0; j < i-1; j++)
            {
                /* code */
                int sum=ret[i-1][j]+ret[i-1][j+1];
                v.push_back(sum);

            }
            v.push_back(1);
            ret.push_back(v);
        }
        return ret;
    }
};