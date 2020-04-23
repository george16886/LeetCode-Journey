#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                ans += (sum == k);
            }
        }

        return ans;
    }
};

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        hmap[0]++;

        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += hmap[sum - k];
            hmap[sum]++;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Input: nums = [ ";
    for (int i : nums)
        cout << i << " ";
    cout << "], k = " << k << endl;
    cout << "Output: " << solution.subarraySum(nums, k) << endl;

    return 0;
}
