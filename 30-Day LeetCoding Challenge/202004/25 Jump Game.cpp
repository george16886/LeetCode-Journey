#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxJump = 0;
        for (int i = 0; i < n; i++) {
            if (i <= maxJump)
                maxJump = max(nums[i] + i, maxJump);
        }

        return (maxJump >= n - 1);
    }
};

class Solution3 {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }

        return true;
    }
};

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxJump = 0;
        for (int i = 0; i < n; i++) {
            if (maxJump >= n - 1)
                return true;
            if (i <= maxJump)
                maxJump = max(nums[i] + i, maxJump);
        }

        return (maxJump >= n - 1);
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> input = {2, 3, 1, 1, 4};
    cout << "Input: [ ";
    for (const int i : input)
        std::cout << i << " ";
    cout << "]" << endl;
    cout << "Output: " << boolalpha << solution.canJump(input) << endl
         << endl;

    input = {3, 2, 1, 0, 4};
    cout << "Input: [ ";
    for (const int i : input)
        std::cout << i << " ";
    cout << "]" << endl;
    cout << "Output: " << boolalpha << solution.canJump(input) << endl
         << endl;

    return 0;
}
