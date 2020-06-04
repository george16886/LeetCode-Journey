#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> productPrefix(n, 1);
        for (int i = 0; i < n - 1; i++)
            productPrefix[i + 1] = productPrefix[i] * nums[i];

        vector<int> productSuffix(n, 1);
        for (int i = n - 1; i > 0; i--)
            productSuffix[i - 1] = productSuffix[i] * nums[i];

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = productPrefix[i] * productSuffix[i];

        return ans;
    }
};

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n - 1; i++)
            ans[i + 1] = ans[i] * nums[i];

        int suffix = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> input = {1, 2, 3, 4};
    cout << "Input: [ ";
    for (auto i : input)
        cout << i << " ";
    cout << "] " << endl;

    vector<int> output = solution.productExceptSelf(input);
    cout << "Output: [ ";
    for (auto i : output)
        cout << i << " ";
    cout << "] " << endl;

    return 0;
}
