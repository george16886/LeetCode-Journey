#include <iostream>
#include <vector>
using namespace std;

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
   public:
    int get(int x, int y);
    vector<int> dimensions();
};

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<vector<int>> mat = {{0, 0}, {1, 1}};

    cout << "Input:\n";
    cout << "[" << endl;
    for (auto row : mat) {
        cout << " [ ";
        for (auto i : row)
            cout << i << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}
