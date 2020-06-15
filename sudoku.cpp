#include<iostream>
#define SIZE 9
using namespace std;

int board[SIZE][SIZE] = {
		{6,5,0,8,7,3,0,9,0},
	{0,0,3,2,5,0,0,0,8},
	{9,8,0,1,0,4,3,5,7},
	{1,0,5,0,0,0,0,0,0},
	{4,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,5,0,3},
	{5,7,8,3,0,1,0,2,6},
	{2,0,0,0,4,8,9,0,0},
	{0,9,0,6,2,5,0,8,1}
};

void Print()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
			cout << board[i][j] << " ";
		cout << endl << endl;
	}
}
bool checkAvailableCell(int* row, int* col)
{
	int num_assigned = 0;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			if (board[i][j] == 0)
			{
				*row = i; *col = j;
				num_assigned = 1;
				return num_assigned;
			}
	return num_assigned;
}

bool isSafe(int row, int col, int num)
{
	for (int i = 0; i < SIZE; ++i)
		if (board[row][i] == num) return false;
	for (int j = 0; j < SIZE; ++j)
		if (board[j][col] == num) return false;
	int x = (row / 3) * 3, y = (col / 3) * 3;
	for (int i = x; i < x + 3; ++i)
		for (int j = y; j < y + 3; ++j)
			if (board[i][j] == num) return false;
	return true;
}

bool Sudoku()
{
	int row, col;
	if (checkAvailableCell(&row, &col) == 0) return true;
	for (int i = 1; i <= SIZE; ++i)
		if (isSafe(row, col, i) == true)
		{
			board[row][col] = i;
			if (Sudoku()) return true;
			board[row][col] = 0;
		}
	return false;
}

int main()
{
	if (Sudoku())  Print();
	else cout << "No solutions." << endl;
	return 0;
}