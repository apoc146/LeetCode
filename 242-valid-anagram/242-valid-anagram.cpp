class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(s.size()!=t.size() || map.count(t[i])==0 || map[t[i]]<=0){
                return false;
            }
            map[t[i]]--;
        }
        return true;
    }
};