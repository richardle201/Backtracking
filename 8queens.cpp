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

/*bool Available(int board[BOARDSIZE][BOARDSIZE], int row, int col)
{
    for(int i=0;i<col;++i)
        if(board[row][i]==1) return false;
    for(int i=row,j=col;i>=0 && j>=0;--i,--j)
        if(board[i][j]==1) return false;
    for(int i=row,j=col;i<=BOARDSIZE && j>=0;++i,--j)
        if(board[i][j]==1) return false;
    return true;
}

bool PlaceQueen(int board[BOARDSIZE][BOARDSIZE], int col)
{

    if(col>=BOARDSIZE) return true;
    else{
        for(int i=0;i<BOARDSIZE;++i)
            if(Available(board,i,col))
            {
                board[i][col]=1;
                if(PlaceQueen(board,col+1)) return true;
                board[i][col]=0;
            }
    }
    return false;
}*/

bool Available(int board[BOARDSIZE][BOARDSIZE], int row, int col)
{
    for(int i=0;i<row;++i)
        if(board[i][col]==1) return false;
    for(int i=row,j=col;i>=0 && j>=0;--i,--j)
        if(board[i][j]==1) return false;
    for(int i=row,j=col;i<=BOARDSIZE && j>=0;++i,--j)
        if(board[i][j]==1) return false;
    return true;
}

bool PlaceQueen(int board[BOARDSIZE][BOARDSIZE], int row)
{

    if(row>=BOARDSIZE) return true;
    else{
        for(int i=0;i<BOARDSIZE;++i)
            if(Available(board,row,i))
            {
                board[row][i]=1;
                if(PlaceQueen(board,row+1)) return true;
                board[row][i]=0;
            }
    }
    return false;
}

int main()
{
    int board[BOARDSIZE][BOARDSIZE]={0};
    if(PlaceQueen(board,0))
        Print(board);
    else cout<<"No solutions"<<endl;
    return 0;
}