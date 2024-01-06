class LRUCache {
public:
    int  capacity=capacity;
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>> cache;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    void makeThisRecent(int key){
        //delete from ll
        this->dll.erase(cache[key].first);
        
        //insert into ll's front
        dll.push_front(key);

        //update cache to point to ll'front 
        cache[key].first=dll.begin();
    }


    int get(int key) {
        if(this->cache.count(key)!=0){
            int cacheVal=this->cache[key].second;
            this->makeThisRecent(key);
            return cacheVal; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)!=0){
            //key exists so just update
            cache[key].second=value;
            this->makeThisRecent(key);
        }else{
            //first insert as this is most recent
            //so has to go in no matter what
            //later evict extras
            dll.push_front(key);
            this->cache[key]=make_pair(this->dll.begin(),value);            
        }

        while(dll.size()>this->capacity){
            int key=dll.back();
            cache.erase(key);
            dll.pop_back();
        }
    }
};