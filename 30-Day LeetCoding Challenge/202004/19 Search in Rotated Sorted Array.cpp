#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) return i;

        return -1;
    }
};

class Solution2 {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[left]) {
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] < nums[left]) {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Input: nums = [ ";
    for (auto i : nums)
        cout << i << " ";
    cout << "], target = " << target << endl;
    cout << "Output: " << solution.search(nums, target) << endl
         << endl;

    target = 3;
    cout << "Input: nums = [ ";
    for (auto i : nums)
        cout << i << " ";
    cout << "], target = " << target << endl;
    cout << "Output: " << solution.search(nums, target) << endl
         << endl;

    return 0;
}
