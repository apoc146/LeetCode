class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magazineMap;
        
        for(int i=0;i<magazine.size();i++){
            magazineMap[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            if(magazineMap.count(ransomNote[i])==0 || magazineMap[ransomNote[i]]<=0){
                return false;
            }
            magazineMap[ransomNote[i]]--;
        }
        return true;
    }
};