// C++ Program to check whether given sudoku is valid
#include <iostream>
#include <vector>
using namespace std;

// Checks for duplicates in the current row
bool validRow(vector<vector<int>>& mat, int row) {

    // Visited array to track occurrences
    vector<int> vis(10, 0);

    for (int i = 0; i < 9; i++) {

        // If the cell is not empty
        if (mat[row][i] != 0) {
            int val = mat[row][i];

            // If duplicate is found
            if (vis[val] != 0)
                return false;

            // Mark the number as visited
            vis[val]++;
        }
    }
    return true;
}

// Checks for duplicates in the current column
bool colValid(vector<vector<int>>& mat, int col) {

    // Visited array to track occurrences
    vector<int> vis(10, 0);

    for (int i = 0; i < 9; i++) {

        // If the cell is not empty
        if (mat[i][col] != 0) {
            int val = mat[i][col];

            // If duplicate is found
            if (vis[val] != 0)
                return false;

            // Mark the number as visited
            vis[val]++;
        }
    }
    return true;
}

// Checks for duplicates in the current 3x3 submatrix
bool subMatValid(vector<vector<int>>& mat, 
                    int startRow, int startCol) {

    // Visited array to track occurrences
    vector<int> vis(10, 0);

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            // Current element in the submatrix
            int curr = mat[row + startRow][col + startCol];

            // If the cell is not empty
            if (curr != 0) {

                // If duplicate is found
                if (vis[curr] != 0)
                    return false;

                // Mark the number as visited
                vis[curr]++;
            }
        }
    }
    return true;
}

// Validates the Sudoku board
bool isValid(vector<vector<int>>& mat) {
  
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // Check if the row, column,
            // or submatrix is invalid
            if (!validRow(mat, i) || !colValid(mat, j)
                || !subMatValid(mat, i - i % 3, j - j % 3))
                return false; 
        }
    }
    return true; 
}

int main() {

    vector<vector<int>> mat = {
        {9, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 5, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    cout << (isValid(mat) ? "true" : "false") << endl;
    return 0;
}
