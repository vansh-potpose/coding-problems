class Solution {
int sum;
public:

    void NQ(vector<int> &board, int index)
    {
        if(index == board.size())
        {
            sum++;
            return;
        }

        for(int i = 0; i < board.size(); i++)
        {
            bool flag = true;
            for(int j = 0; j < index; j++)
            {
                // horizontal check
                if(board[j] == i)
                {
                    flag = false;
                    break;
                }
                // diagonal check
                if(abs(board[j] - i) == abs(j - index))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                // mark entry and proceed to next step
                board[index] = i;
                NQ(board,index + 1);
            }
        }
    }
    
    int totalNQueens(int n) {
        sum = 0;
        vector<int> board(n,0);
        NQ(board,0);
        return sum;
    }
};