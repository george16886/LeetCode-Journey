class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string ans = "";
        if (size == 0) return ans;
        int range = strs[0].length();
        int ans_len = 0;
        for (int k = 0; k < range; k++) { 
        int same = 1;           
            for (int j = 0; j < size -1; j++) {
                if (strs[j+1][ans_len] == strs[j][ans_len]) same++;
            }
            if (same == size) {
                ans_len++;
            }
        }
        for (int i = 0; i < ans_len; i++) ans = ans + strs[0][i];
        return ans;
    }
};
