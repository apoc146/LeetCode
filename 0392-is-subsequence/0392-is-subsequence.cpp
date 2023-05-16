class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==""){
            return true;
        }
        int t_size = t.size();
        bool ret=false;
        int track=-1;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int index=(track==-1?0:track)+t.substr(track==-1?0:track).find(ch);
            if(index!=string::npos){
                bool test= (int(index)>track);
                if(index>=track){
                    track=index+1;
                    ret=true;
                }else{
                    ret=false;
                    break; 
                }
            }else{
                ret=false;
                break;
            }
        }
        return ret;
    }
};