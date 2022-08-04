class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        int l=0;
        int r=0;
        unordered_map<char,int> map;
        int max_freq_char_count=0;
        
        while(r<s.size()){
            map[s[r]]++;
            max_freq_char_count=max(max_freq_char_count,map[s[r]]);
            int diff_char_count=r-l+1-max_freq_char_count;
            
            bool condition= (diff_char_count <= k);
            
            while(r-l+1-max_freq_char_count>k){
                map[s[l]]--;
                l++;
            }
            
            res=max(res,r-l+1);
            r++;
            
//             if(condition==true){
//                 res=max(res,r-l+1);
//                 r++;
//             }else{
//                 map[s[l]]--;
//                 l++;
//             }
        }
        return res;
    }
};