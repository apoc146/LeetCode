class Solution {
public:
    
    // my recursive function 
    void foo(vector<int>& vec, int carry, int lsb){
        if(carry==0){
            //do nothing
            return ;
        }
        
        if(lsb>=vec.size()){
            vec.insert(vec.begin(),carry);
            return ;
        }
        
        int vecSize=vec.size();
        int num=vec[vecSize-1-lsb];
        if(num<9){
            vec[vecSize-1-lsb]++;
            foo(vec,0,lsb+1);
        }else{
            vec[vecSize-1-lsb]=0;
            foo(vec,1,lsb+1);
        }
    }
    
    vector<int> plusOne(vector<int>& digits) {
        foo(digits,1,0);
        return digits;
    }
};