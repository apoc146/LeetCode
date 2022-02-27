class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charVec(26,-2);
        for(int i=0;i<s.size();i++){
            charVec[s[i]-97]=(charVec[s[i]-97]>-2?-1:i);
        }
        //find min +ve value
        int ret=-1;
        for(int i=0;i<charVec.size();i++){
            if(charVec[i]>-1){
                if(ret==-1){
                    ret=charVec[i];
                }else{
                    ret=min(ret,charVec[i]);
                }
            }
        }
        return ret;
    }
};