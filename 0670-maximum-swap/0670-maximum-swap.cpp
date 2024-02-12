class Solution {
public:
    int maximumSwap(int num) {
        string numStr=to_string(num);
        vector<int> loc(10,-1);
        int n=numStr.size(); 
        
        //save idx location
        for(int i=0;i<n;i++){
            loc[numStr[i]-'0']=i;    
        }
        
        for(int i=0;i<n;i++){
            //for each digit check if there is a high digit on its right
            //then swap
            for(int val=9;val>=0 and val>(numStr[i]-'0');val--){
                int idxOfVal=loc[val];
                if(idxOfVal>i){
                    swap(numStr[i],numStr[idxOfVal]);
                    return stoi(numStr);
                }
            }
        } 
        return stoi(numStr);
    }
};