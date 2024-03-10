class comp {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        int dist1 = pow(a[0], 2) + pow(a[1], 2);
        int dist2 = pow(b[0], 2) + pow(b[1], 2);
        return dist1 > dist2; // Compare distances in ascending order
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>,vector<vector<int>>,comp> heap(points.begin(),points.end());
        while(k-->0){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};