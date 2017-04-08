class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int tmp = 1;
        int idx = 0;
        if (s.length() == 0) ans = 0;
        else {
            for (int i = 0; i < s.length(); i++) {
                for (int j = idx; j < i; j++) {
                    if (s.at(i) == s.at(j)) {
                        idx = j + 1;
                    }
                    else {
                        tmp++;
                    }
                }
                if (tmp > ans) {
                    ans = tmp;
                }
                tmp = 1;
            }
        }
        return ans;
    }
};
