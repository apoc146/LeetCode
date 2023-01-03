class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> vec(n+1,0);
        if(n<2){
            return n;
        }
        vec[0]=0;
        vec[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                vec[i]=vec[i/2];
            }else{
                vec[i]=vec[i/2]+vec[(i/2)+1];
            }
        }
        return *max_element(vec.begin(),vec.end());
    }
};