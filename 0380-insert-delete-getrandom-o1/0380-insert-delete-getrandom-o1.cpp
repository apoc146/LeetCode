class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> map; //value, index;
    RandomizedSet() {
        //nothing to do;
    }
    
    bool insert(int val) {
        if(map.count(val)!=0){
            return false;
        }
        vec.push_back(val);
        int idx=vec.size()-1;
        map[val]=idx;
        return true;
    }
    
    bool remove(int val) {
        if(map.count(val)==0){
            return false;
        }
        int idx=map[val];
        int lastVal=vec.back();
        map[lastVal]=idx;

        swap(vec[idx], vec[vec.size()-1]);
        vec.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */