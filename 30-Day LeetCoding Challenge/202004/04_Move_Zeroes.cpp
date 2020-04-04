#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int firstZeroIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                int tmp = nums[firstZeroIndex];
                nums[firstZeroIndex] = nums[i];
                nums[i] = tmp;
                firstZeroIndex++;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> input = {0, 1, 0, 3, 12};

    cout << "Input: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    solution.moveZeroes(input);
    cout << "Output: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
