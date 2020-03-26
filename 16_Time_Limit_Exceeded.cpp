class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int s = nums.size();
        int min = 2147483647;
        int ans;
        if (s == 0) return 0;
        else if (s == 1) return nums[0];
        else if (s == 2) return nums[0] + nums[1];
        else if (s == 3) return nums[0] + nums[1] + nums[2];
        else {
            for (int k = 0; k < s - 2; k++) {
                for (int j = k + 1; j < s - 1; j++) {
                    for (int i = j + 1; i < s; i++) {
                        int tmp = nums[k] + nums[j] + nums[i];
                        int gap = tmp - target;                    
                        if (gap < 0) gap = -gap;
                        if (gap < min) {
                            min = gap;
                            ans = tmp;    
                        }
                    }
                }
            }
            return ans;
        }
    }
};
