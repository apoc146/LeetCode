class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int i=0;
        while(i<s.size()){
            int j=i;
            set<char> set;
            unordered_map<char,int> map;
            
            
            while(j<s.size() && map.count(s[j])==0){
                map[s[j]]=j;
                j++;
            }
            
            maxlen=max(maxlen,j-i);
            if(j<s.size()){
                i=map[s[j]]+1;
            }else{
                i++;
            }
        }
        return maxlen;
    }
};