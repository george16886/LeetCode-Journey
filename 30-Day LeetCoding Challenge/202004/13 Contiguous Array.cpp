#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {  // Time Limit Exceeded
   public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;

        int ans = 0;
        for (int j = 0; j < n - 1; j++) {
            if (n - j <= ans) break;

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

class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int sum = 0;

        unordered_map<int, int> hmap = {{0, -1}};
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] * 2) - 1;
            if (!hmap.count(sum))
                hmap[sum] = i;
            else if (i - hmap[sum] > ans)
                ans = i - hmap[sum];
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> input = {0, 1};

    cout << "Input: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    int output = solution.findMaxLength(input);
    cout << "Output: " << output << endl;

    input = {0, 1, 0};

    cout << "Input: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    output = solution.findMaxLength(input);
    cout << "Output: " << output << endl;

    return 0;
}
