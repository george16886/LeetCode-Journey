#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> ans = grid;
        for (int row = 1; row < rows; row++)
            ans[row][0] = ans[row - 1][0] + grid[row][0];
        for (int col = 1; col < cols; col++)
            ans[0][col] = ans[0][col - 1] + grid[0][col];

        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                ans[row][col] = min(ans[row - 1][col], ans[row][col - 1]) + grid[row][col];
            }
        }

        return ans[rows - 1][cols - 1];
    }
};

class Solution2 {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> ans = grid;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row > 0 && !col)
                    ans[row][0] = ans[row - 1][0] + grid[row][0];
                else if (col > 0 && !row)
                    ans[0][col] = ans[0][col - 1] + grid[0][col];
                else if (row > 0 && col > 0)
                    ans[row][col] = min(ans[row - 1][col], ans[row][col - 1]) + grid[row][col];
            }
        }

        return ans[rows - 1][cols - 1];
    }
};

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row > 0 && !col)
                    grid[row][0] = grid[row - 1][0] + grid[row][0];
                else if (col > 0 && !row)
                    grid[0][col] = grid[0][col - 1] + grid[0][col];
                else if (row > 0 && col > 0)
                    grid[row][col] = min(grid[row - 1][col], grid[row][col - 1]) + grid[row][col];
            }
        }

        return grid[rows - 1][cols - 1];
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<vector<int>> grid =
        {{1, 3, 1},
         {1, 5, 1},
         {4, 2, 1}};

    cout << "Input:\n";
    cout << "[" << endl;
    for (auto g : grid) {
        cout << " [ ";
        for (auto c : g)
            cout << c << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
    cout << "Output: " << solution.minPathSum(grid) << endl;

    return 0;
}
