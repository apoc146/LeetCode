class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            map[word].push_back(strs[i]);
        }
        
        unordered_map<string,vector<string>>::iterator it;
        
        for(it=map.begin();it!=map.end();it++){
                res.push_back(it->second);
        }
        return res;
        
    }
};