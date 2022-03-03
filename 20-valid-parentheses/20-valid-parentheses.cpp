class Solution {
public:
    bool isValid(string s) {

        set<char> left={'(','{','['};
        set<char> right={')','}',']'};
        unordered_map<char,char> charMap{{'(',')'},{'{','}'},{'[',']'},{')','('},{'}','{'},{']','['}};
        
        stack<char> stk;

        for(int i=0;i<s.size();i++){
            if(left.find(s[i])!=left.end()){
                stk.push(s[i]);
            }else{
                if(!stk.empty() && charMap[s[i]]==stk.top()){
                    stk.pop();
                }else{
                    return false;
                }
            }
        } 

        return (stk.size()==0?true:false);
    }
};