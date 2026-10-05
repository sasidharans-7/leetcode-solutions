#include <stdbool.h>

#define SIZE 9

bool isSafe(char** board, int row, int col, char num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuHelper(char** board, int row, int col) {
    if (row == SIZE - 1 && col == SIZE) {
        return true;
    }

    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (board[row][col] != '.') {
        return solveSudokuHelper(board, row, col + 1);
    }

    for (char num = '1'; num <= '9'; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudokuHelper(board, row, col + 1)) {
                return true;
            }

            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solveSudokuHelper(board, 0, 0);
}