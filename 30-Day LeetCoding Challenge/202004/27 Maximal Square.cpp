#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;

        int n = min(matrix.size(), matrix[0].size());
        while (n > 0) {
            for (int x = 0; x <= matrix[0].size() - n; x++) {
                for (int y = 0; y <= matrix.size() - n; y++) {
                    if (squareCheck(matrix, x, y, n))
                        return n * n;
                }
            }

            n--;
        }

        return 0;
    }

    bool squareCheck(vector<vector<char>>& matrix, int x, int y, int length) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (matrix[y + j][x + i] == '0')
                    return false;
            }
        }

        return true;
    }
};

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxLength = 0;

        vector<vector<int>> dp(rows, vector<int>(cols));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!row || !col)
                    dp[row][col] = (matrix[row][col] == '1') ? 1 : 0;
                else if (matrix[row][col] == '1')
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row][col - 1], dp[row - 1][col])) + 1;

                maxLength = max(maxLength, dp[row][col]);
            }
        }

        return maxLength * maxLength;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<vector<char>> matrix =
        {{'1', '0', '1', '0', '0'},
         {'1', '0', '1', '1', '1'},
         {'1', '1', '1', '1', '1'},
         {'1', '0', '0', '1', '0'}};

    cout << "Input:\n\n";
    for (auto m : matrix) {
        for (auto c : m)
            cout << c;
        cout << "\n";
    }
    cout << "\nOutput: " << solution.maximalSquare(matrix) << endl
         << endl;

    matrix = {{'1'}};

    cout << "Input:\n\n";
    for (auto m : matrix) {
        for (auto c : m)
            cout << c;
        cout << "\n";
    }
    cout << "\nOutput: " << solution.maximalSquare(matrix) << endl
         << endl;

    return 0;
}
