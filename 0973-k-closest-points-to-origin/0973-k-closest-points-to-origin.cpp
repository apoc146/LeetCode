class comp {
public:
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
        int dist1 = pow(a[0], 2) + pow(a[1], 2);
        int dist2 = pow(b[0], 2) + pow(b[1], 2);
        return dist1 > dist2;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::vector<std::vector<int>> ans;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comp> heap(points.begin(), points.end());
        while (k-- > 0) {
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};