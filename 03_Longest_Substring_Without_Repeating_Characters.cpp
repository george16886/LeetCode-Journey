#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1 {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int tmp = 1;
        int idx = 0;

        if (s.length() == 0)
            ans = 0;
        else {
            for (int i = 1; i < s.length(); i++) {
                for (int j = idx; j < i; j++) {
                    if (s.at(i) == s.at(j)) {
                        idx = j + 1;
                    } else {
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

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int idx = -1;
        unordered_map<int, int> hmap;

        for (int i = 0; i < s.size(); i++) {
            if (hmap.count(s[i]) && (hmap[s[i]] > idx))
                idx = hmap[s[i]];

            hmap[s[i]] = i;
            ans = max(ans, i - idx);
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    string a = "abcabcbb";
    string b = "bbbbb";
    string c = "pwwkew";
    int ans = solution.lengthOfLongestSubstring(a);
    cout << "The answer of \"" << a << "\" is: " << ans << endl;
    ans = solution.lengthOfLongestSubstring(b);
    cout << "The answer of \"" << b << "\" is: " << ans << endl;
    ans = solution.lengthOfLongestSubstring(c);
    cout << "The answer of \"" << c << "\" is: " << ans << endl;
    return 0;
}