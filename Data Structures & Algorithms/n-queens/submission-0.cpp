class Solution {
public:
    // Check if placing queen at (row, col) is safe
    bool isSafe(const vector<int>& stack, int row, int col) {
        for (int r = 0; r < row; r++) {
            int c = stack[r];

            // Same column or same diagonal
            if (c == col || abs(c - col) == abs(r - row)) {
                return false;
            }
        }

        return true;
    }

    // Store the current board configuration
    void addSolution(const vector<int>& stack, int n,
                     vector<vector<string>>& result) {

        vector<string> board;

        for (int i = 0; i < n; i++) {
            string row(n, '.');

            row[stack[i]] = 'Q';

            board.push_back(row);
        }

        result.push_back(board);
    }

    // Recursive backtracking function
    void solveNQueens(int row, int n,
                      vector<int>& queenStack,
                      vector<vector<string>>& result) {

        // All queens have been placed
        if (row == n) {
            addSolution(queenStack, n, result);
            return;
        }

        // Try every column in the current row
        for (int col = 0; col < n; col++) {

            if (isSafe(queenStack, row, col)) {

                // Place queen
                queenStack.push_back(col);

                // Move to next row
                solveNQueens(row + 1, n, queenStack, result);

                // Backtrack
                queenStack.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;

        // External stack storing column of queen for each row
        vector<int> queenStack;

        solveNQueens(0, n, queenStack, result);

        return result;
    }

};
