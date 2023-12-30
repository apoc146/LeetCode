class HitCounter {
public:
    vector<long long int> db;
    HitCounter() {
        //do nothing;
    }
    
    void hit(int timestamp) {
        db.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int count=0;
        for(int idx=db.size()-1;idx>=0;--idx){
            if(db[idx]>timestamp-300){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */