#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int first_zero = 0;
        bool detect_zero = false;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i] && !detect_zero) {
                first_zero = i;
                detect_zero = true;
            }
            if (nums[i]) {
                int tmp = nums[first_zero];
                nums[first_zero] = nums[i];
                nums[i] = tmp;
                first_zero++;
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
