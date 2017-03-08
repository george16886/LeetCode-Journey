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
