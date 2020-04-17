#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   private:
    int rows;
    int cols;

   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();

        int island = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    visitIsland(grid, visited, row, col);
                    island++;
                }
            }
        }

        return island;
    }

    void visitIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        bool withinBound = (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
        if (withinBound)
            if (grid[row][col] == '1' && !visited[row][col]) {
                visited[row][col] = true;
                visitIsland(grid, visited, row - 1, col);
                visitIsland(grid, visited, row + 1, col);
                visitIsland(grid, visited, row, col - 1);
                visitIsland(grid, visited, row, col + 1);
            }
    }
};

class Solution {
   private:
    int rows;
    int cols;

   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();

        int island = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {
                    visitIsland(grid, row, col);
                    island++;
                }
            }
        }

        return island;
    }

    void visitIsland(vector<vector<char>>& grid, int row, int col) {
        bool withinBound = (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
        if (withinBound)
            if (grid[row][col] == '1') {
                grid[row][col] = '0';
                visitIsland(grid, row - 1, col);
                visitIsland(grid, row + 1, col);
                visitIsland(grid, row, col - 1);
                visitIsland(grid, row, col + 1);
            }
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<vector<char>> grid =
        {{'1', '1', '1', '1', '0'},
         {'1', '1', '0', '1', '0'},
         {'1', '1', '0', '0', '0'},
         {'0', '0', '0', '0', '0'}};

    cout << "Input:\n";
    for (auto g : grid) {
        for (auto c : g)
            cout << c;
        cout << "\n";
    }
    cout << "Output: " << solution.numIslands(grid) << endl
         << endl;

    grid =
        {{'1', '1', '0', '0', '0'},
         {'1', '1', '0', '0', '0'},
         {'0', '0', '1', '0', '0'},
         {'0', '0', '0', '1', '1'}};

    cout << "Input:\n";
    for (auto g : grid) {
        for (auto c : g)
            cout << c;
        cout << "\n";
    }
    cout << "Output: " << solution.numIslands(grid) << endl
         << endl;

    return 0;
}
