#include<iostream>
#define BOARDSIZE 8
using namespace std;




void Print(int board[BOARDSIZE][BOARDSIZE])
{
    for(int i=0;i<BOARDSIZE;++i)
    {      
        for(int j=0;j<BOARDSIZE;++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

bool Available(int row, int col,int board[BOARDSIZE][BOARDSIZE])
{
    if (row >= 0 && row < BOARDSIZE && col >= 0 && col < BOARDSIZE && board[row][col] ==0)
        return true;
    else return false;
}

bool Tour(int row, int col,int board[BOARDSIZE][BOARDSIZE],int stepCount, int moveRow[BOARDSIZE], int moveCol[BOARDSIZE])
{
    if(stepCount>BOARDSIZE*BOARDSIZE) return true;
    for(int i=0;i<BOARDSIZE;++i)
        {
            int newRow=row+moveRow[i];
            int newCol=col+moveCol[i];
            if(Available(newRow,newCol,board))
                {
                    board[newRow][newCol]=stepCount;
                    if(Tour(newRow,newCol,board,stepCount+1,moveRow,moveCol)==true)
                        return true;
                    else board[newRow][newCol]=0;

                }
        }
    return false;
}


int main()
{
    int board[BOARDSIZE][BOARDSIZE]={0};
    int moveRow[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int moveCol[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };        
    int row=-1,col=-1;
    cout<<"Initialize position of the knight:"<<endl;
    cout<<"Row: "<<endl;
    cin>>row;
    cout<<"Column: "<<endl;
    cin>>col;
    board[row][col]=1;
    if(Tour(row,col,board,1,moveRow,moveCol)==true) Print(board);
    else cout<<"No solutions."<<endl;
    return 0;
}
