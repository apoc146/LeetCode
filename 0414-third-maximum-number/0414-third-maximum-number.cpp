class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> set(nums.begin(),nums.end());
        priority_queue<int> heap(set.begin(),set.end());
        if(heap.size()<3){
            return heap.top();
        }
        
        heap.pop();
        heap.pop();
        return heap.top();
    }
};