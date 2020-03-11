#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    vector<int> ans = solution.twoSum(nums, target);
    cout << "The answer is: [" << ans[0] << ", " << ans[1] << "]." << endl;
    return 0;
}
