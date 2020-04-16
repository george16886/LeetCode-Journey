#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;

        int ans = 0;
        for (int j = 0; j < n - 1; j++) {
            int sum = (nums[j] * 2) - 1;
            for (int i = j + 1; i < n; i++) {
                sum += (nums[i] * 2) - 1;
                int len = i - j + 1;
                if ((sum == 0) && (len > ans))
                    ans = len;
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> input = {0, 1};
    input = {0, 0, 1, 0, 0, 0, 1, 1};

    cout << "Input: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    int output = solution.findMaxLength(input);
    cout << "Output: " << output << endl;

    return 0;
}
