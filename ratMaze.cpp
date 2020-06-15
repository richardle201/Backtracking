#include<iostream>
using namespace std;
#define SIZE 5
int maze[SIZE][SIZE]={
    {0,1,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
    {0,0,1,0,0},
    {1,0,0,1,0}
    };

int res[SIZE][SIZE]={0};

void Print()
{
    for(int i=0;i<SIZE;++i)
    {
        for(int j=0;j<SIZE;++j)
            cout<<res[i][j]<<"\t";
        cout<<endl<<endl;
    }
}

bool isSafe(int row, int col)
{
    if(row<0||row>=SIZE) return false;
    if(col<0||col>=SIZE) return false;
    if(maze[row][col]==1) return false;
    if(res[row][col]==1) return false;
    return true;
}

bool Maze(int row, int col)
{
    if(row==SIZE-1 && col==SIZE-1)
    {
        res[row][col]=1;
        return true;
    }
    if(isSafe(row,col))
    {
        res[row][col]=1;
        if(Maze(row+1,col)) return true;
        if(Maze(row,col+1)) return true;
        if(Maze(row,col-1)) return true;
        if(Maze(row-1,col)) return true;
        res[row][col]=0;
    }
    return false;
        

}

int main()
{
    if(Maze(0,0)) Print();
    return 0;
}