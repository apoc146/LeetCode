class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        int l=0;                        //i and j to implement sliding window
        int r=0;
        unordered_map<char,int> map;    //map to track count of all characters in window
        int max_freq_char_count=0;      //Highest count from the map above
        
        while(r<s.size()){
            //increment map count and update frequence count.
            map[s[r]]++;
            max_freq_char_count=max(max_freq_char_count,map[s[r]]);

            //while the condition is not true decrease the window by i++. Accordingly reduce count of those chars.
            while(r-l+1-max_freq_char_count>k){
                map[s[l]]--;
                l++;
            }
            
            //find length of window once condition is satisfied(exists while loop)
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};