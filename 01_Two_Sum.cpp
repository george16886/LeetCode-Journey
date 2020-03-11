#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int idx1, idx2;
        vector<int> v(2);
        
        for (int i = 0; i < nums.size(); i++) {
            int ans = target - nums[i];
            idx1 = i;
            for (int j = 1 + i; j < nums.size(); j++) {
                ans = ans - nums[j];
                idx2 = j;
                if (ans == 0) {
                    v[0] = idx1;
                    v[1] = idx2;
                    return v;
                }
                ans = ans + nums[j];
            }
        }
    }
};

int main(int argc, char **argv)
{
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
