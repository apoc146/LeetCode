class Solution {
public:
    
    // my recursive function 
    void foo(vector<int>& vec, int carry, int lsb){
        if(carry==0){
            //do nothing
            return ;
        }
        
        //single element with carry
        if(lsb>=vec.size()){
            vec.insert(vec.begin(),carry);
            return ;
        }
        
        int vecSize=vec.size();
        int num=vec[vecSize-1-lsb];
        
        //digit is <9
        if(num<9){
            vec[vecSize-1-lsb]++;
            //actually ends in next call
            foo(vec,0,lsb+1);
        }else{
            vec[vecSize-1-lsb]=0;
            //gives carry and now does the same stuff until preceding index
            foo(vec,1,lsb+1);
        }
    }
    
    vector<int> plusOne(vector<int>& digits) {
        foo(digits,1,0);
        return digits;
    }
};