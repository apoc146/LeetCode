class Solution {
public:
    bool divisorGame(int n) {
//         if(n==0 || n==1){
//             return false;
//         }

//         if(n==2){
//             return true;
//         }
        

//         bool ans=false;
        
//         for(int i=1;(i<n && n%i==0);i++){
//             ans|=divisorGame(n-i);
//         }

//         return ans;
        
        return n%2==0;
    }
};