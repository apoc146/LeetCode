class Solution {
public:
    vector<int> v;
    void printVec(vector<int> vec){
        for(auto& ele:vec){
            cout<<ele<<" "; 
        }
        cout<<"\n";
    }
    Solution(vector<int>& w) {
        v=w;
        int temp=0;
        for(int i=0;i<v.size();i++){
            v[i]=temp+v[i];
            temp=v[i];
        }
        printVec(v);
    }
    
    int pickIndex() {
        int val=rand()%(v.back());
        cout<<val<<"\n";
        auto itr=upper_bound(v.begin(),v.end(),val);
        return distance(v.begin(),itr);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */