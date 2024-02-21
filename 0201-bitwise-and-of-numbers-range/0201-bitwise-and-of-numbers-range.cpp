// https://www.youtube.com/watch?v=-qrpJykY2gE
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            cnt++;
       }
        cout<<cnt<<endl;
        while(cnt-->0){
            left<<=1;
        }
        return left;
    }
};