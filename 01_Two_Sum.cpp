#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if ((nums[i] + nums[j]) == target)
                    return {i, j};

        return {};
    }
};
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;

        for (int i = 0; i < nums.size(); i++) {
            if (hmap.count(target - nums[i]))
                return {hmap[target - nums[i]], i};
            hmap[nums[i]] = i;
        }

        return {};
    }
};

int main(int argc, char** argv) {
    Solution solution;
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    vector<int> nums = {3, 2, 3};
    int target = 6;

    vector<int> ans = solution.twoSum(nums, target);
    cout << "The answer is: [" << ans[0] << ", " << ans[1] << "]." << endl;

    return 0;
}
