#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        multiset<int> diffHeap;
        int bricksUsed = 0;

        for (int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0) {
                diffHeap.insert(diff);
                if (diffHeap.size() > ladders) {
                    bricksUsed += *diffHeap.begin();
                    diffHeap.erase(diffHeap.begin());
                }
                if (bricksUsed > bricks) {
                    return i - 1;
                }
            }
        }
        return n - 1;
    }
};
