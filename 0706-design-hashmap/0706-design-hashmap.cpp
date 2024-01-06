class MyHashMap {
public:
    int size=1e3;
    vector<list<pair<int,int>>> vec;
    
    MyHashMap() {
        vec.resize(size, list<pair<int,int>>(1));
    }
    
    void put(int key, int value) {
        int idx=key%size;
        list<pair<int,int>>::iterator it=vec[idx].begin();
        while(it!=vec[idx].end() and it->first!=key){
            it++;
        }
        if(it!=vec[idx].end()){
            it->second=value;
            return ;
        }
        vec[idx].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int idx=key%size;
        list<pair<int,int>>::iterator it=vec[idx].begin();
        while(it!=vec[idx].end() and it->first!=key){
            it++;
        }
        if(it==vec[idx].end()){
            return -1;
        }
        return it->second;
        
    }
    
    void remove(int key) {
        int idx=key%size;
        auto it=vec[idx].begin();
        while(it!=vec[idx].end() and it->first!=key){
            it++;
        }
        if(it==vec[idx].end()){
            return ;
        }
        vec[idx].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */