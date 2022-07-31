class Solution {
public:
    bool vecCheck(vector<char> row){
        int nums[9]={0};
        for(int i=0;i<row.size();i++){
            if(row[i]=='.'){
                //do nothing
            }else{
                nums[row[i]-'0'-1]++;
            }
        }
        
        for(int i=0;i<9;i++){
            if(nums[i]>1){
                return false;
            }
        }
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool res = true;
        
        //row check
        for(int i=0;i<9;i++){
            res&=vecCheck(board[i]);
        }
        
        //column check
        for(int j=0;j<9;j++){
            vector<char> col;
            for(int i=0;i<9;i++){
                col.push_back(board[i][j]);
            }
            res&=vecCheck(col);
        }
        
        //3x3 Box check
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int x=3*i;
                int y=3*j;
                vector<char> boxElements;
                
                boxElements.push_back(board[x+0][y+0]);
                boxElements.push_back(board[x+0][y+1]);
                boxElements.push_back(board[x+0][y+2]);
                boxElements.push_back(board[x+1][y+0]);
                boxElements.push_back(board[x+1][y+1]);
                boxElements.push_back(board[x+1][y+2]);
                boxElements.push_back(board[x+2][y+0]);
                boxElements.push_back(board[x+2][y+1]);
                boxElements.push_back(board[x+2][y+2]);
                
                res&=vecCheck(boxElements);
            }
        }
        return res;
        
    }
};