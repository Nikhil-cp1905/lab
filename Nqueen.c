#include <stdio.h>
#include <stdbool.h>

#define N 4  // You can change this value for different board sizes

int board[N][N];

// Function to print the board
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve N-Queens using backtracking
bool solveNQueens(int row) {
    if (row == N) {
        printSolution();
        return true;  // If only one solution is needed, return true here
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            res = solveNQueens(row + 1) || res;  // Keep finding all solutions
            board[row][col] = 0;  // Backtrack
        }
    }

    return res;
}

int main() {
    if (!solveNQueens(0))
        printf("No solution exists.\n");
    else
        printf("Solutions printed above.\n");

    return 0;
}

