class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n=tokens.size();
        int score=0;
        int l=0;
        int r=n-1;
        int mx_score=0;
        while(l<=r){
            if(tokens[l]<=power){
                score++;
                power-=tokens[l];
                mx_score=max(mx_score,score);
                l++;
            }else{
                if(score>0){
                    score--;
                    power+=tokens[r];
                    mx_score=max(mx_score,score);
                    r--;
                }else{
                    break;
                }
            }
            
        }
        return mx_score;
    }
};