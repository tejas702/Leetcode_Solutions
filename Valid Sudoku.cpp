class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int row[n];
        int col[n];
        int box[n];
        
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(row));
        memset(box,0,sizeof(row));
        
        for(int i = 0;i < n; i++){
            for(int j = 0;j < n; j++){
                if(board[i][j] == '.') continue;
                
                int value = board[i][j] - '0';
                
                int position = 1 << (value-1);
                int boxpos = (i/3)*3 + j/3;
                if((row[i] & position) || (col[j] & position) || (box[boxpos] & position)){
                    return false;
                }
                row[i] |= position;        
                col[j] |= position;        
                box[boxpos] |= position;        
            }
        }
        
        return true;
    }
};