class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int i=0;
        
        //start at index i
        while(i<s.size()){
            int j=i;
            set<char> set;
            unordered_map<char,int> map;
            
            //loop until you find unique characters
            //maps is used to keep track of characters and their indices
            while(j<s.size() && map.count(s[j])==0){
                map[s[j]]=j;
                j++;
            }
            
            //breaks off the loop only if -> duplicate char or reaching end of string
            maxlen=max(maxlen,j-i);
            if(j<s.size()){
                //detected repeating char so now move 'i' to next of the index of first occurance of this repeated character
                i=map[s[j]]+1;
            }else{
                //reached end of string so i++
                i++;
            }
        }
        return maxlen;
    }
};