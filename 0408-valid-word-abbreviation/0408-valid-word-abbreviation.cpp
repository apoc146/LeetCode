class Solution {
public:
    bool lenCheck(string word, string abbr){
        int wordLen=word.size();
        int abbrLen=0;
        for(int i=0;i<abbr.size();){
            char ch=abbr[i];
            if(isalpha(ch)){
                abbrLen++;
                i++;
            }else{
                string num="";
                while(i<abbr.size() and isdigit(abbr[i])){
                    num+=abbr[i];
                    i++;
                }
                abbrLen+=stoi(num);
            }
        }
        return abbrLen==wordLen;
    }
    
    bool textCheck(string word, string abbr){
        int wordIdx=0;
        int abbrIdx=0;
        while(abbrIdx < abbr.size()){
            
            string num="";
            
            while(isdigit(abbr[abbrIdx])){
                num+=abbr[abbrIdx];
                abbrIdx++;
            }
            
            if(num.front()=='0'){
                return false;
            }
            
            if(num.size()>0){
                wordIdx+=stoi(num);
            }
            
            if(word[wordIdx]==abbr[abbrIdx]){
                //skip
                abbrIdx++;
                wordIdx++;
            }else{
                return false;
            }
        }
        return true;
    }
    
    bool validWordAbbreviation(string word, string abbr) {
        // // length check and str check
        // cout<<lenCheck(word,abbr)<<endl;
        // cout<<textCheck(word,abbr);
        
        if(lenCheck(word,abbr) and textCheck(word,abbr)){
            return true;
        }
        return false;
    }
};