class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int len = nums.size();
        if (len == 0) return 0;
        else {
            for (int i = 0; i < len; i++) {
                if (nums[i] != val) {
                    nums[cnt++] = nums[i];
                }
            }
            return cnt;
        }
    }
};
