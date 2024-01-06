/*
* Map to store {id:exp time}
* Simple
*/
class AuthenticationManager {
public:
    int ttl=0;
    // {id:exp time}
    unordered_map<string,int> cache;
    
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;    
    }
    
    void generate(string tokenId, int currentTime) {
        cache[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(cache.count(tokenId)!=0 and cache[tokenId]>currentTime){
            cache[tokenId]=currentTime+ttl;
        }
        return ;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans=0;
        for(auto& ele:cache){
            if(ele.second > currentTime){
                ans+=1;
            }
        }
        return ans;
    }
};