class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queenStack;
        int solutionCount = 0;

        solveNQueens(0, n, queenStack, solutionCount);

        return solutionCount;

    
    }
    void solveNQueens(int row, int n, vector<int>& queenStack, int& solutionCount) {
    // Base Case: All n queens are placed successfully
        if (row == n) {
            solutionCount++;
            
            return;
        }

        // Try placing a queen in every column for the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(queenStack, row, col)) {
                // Push column position to the external stack
                queenStack.push_back(col);

                // Recursively move to the next row
                solveNQueens(row + 1, n, queenStack, solutionCount);

                // Pop (backtrack) to explore other configurations
                queenStack.pop_back();
            }
        }
    }
    bool isSafe(const vector<int>& stack, int row, int col) {
        for (int r = 0; r < row; r++) {
            int c = stack[r];
            // Check column attack or diagonal attack
            if (c == col || abs(c - col) == abs(r - row)) {
                return false;
            }
        }
        return true;
    }
};