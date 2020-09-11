class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int len = nums.size();
        if (len == 0) return 0;
        else if (len == 1) return 1;
        else {
            for (int i = 0; i < len - 1; i++) {
                if (nums[i] != nums[i + 1]) {
                    nums[cnt++] = nums[i + 1];
                }
            }
            return cnt;
        }
    }
};
