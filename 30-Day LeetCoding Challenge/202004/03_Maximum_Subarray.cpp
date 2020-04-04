#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int maxSubArray(vector<int>& nums) {
        int globalMAX = INT32_MIN;
        int localMAX = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = localMAX + nums[i];
            if (tmp > nums[i])
                localMAX = tmp;
            else
                localMAX = nums[i];

            if (localMAX > globalMAX)
                globalMAX = localMAX;
        }

        return globalMAX;
    }
};

class Solution2 {
   public:
    int maxSubArray(vector<int>& nums) {
        int globalMAX = INT32_MIN;
        int localMAX = 0;
        for (int num : nums) {
            localMAX = max(localMAX + num, num);
            globalMAX = max(localMAX, globalMAX);
        }

        return globalMAX;
    }
};

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        return divideArray(nums, 0, n - 1);
    }

    int divideArray(vector<int>& nums, int left, int right) {
        if (left >= right)
            return nums[left];

        int mid = (left + right) / 2;
        int leftMAX = divideArray(nums, left, mid - 1);
        int rightMAX = divideArray(nums, mid + 1, right);
        int sideMAX = max(leftMAX, rightMAX);

        int midLeftMAX = nums[mid];
        int midLeftSum = nums[mid];
        for (int i = mid - 1; i >= left; i--) {
            midLeftSum += nums[i];
            midLeftMAX = max(midLeftMAX, midLeftSum);
        }
        int midMAX = midLeftMAX;
        int midSum = midLeftMAX;
        for (int i = mid + 1; i <= right; i++) {
            midSum += nums[i];
            midMAX = max(midMAX, midSum);
        }

        int globalMAX = max(midMAX, sideMAX);

        return globalMAX;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Input: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    int output = solution.maxSubArray(input);
    cout << "Output: " << output << endl;

    return 0;
}
