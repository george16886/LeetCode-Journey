#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int max_length = 1;
        int start_idx = 0;

        for (int i = 1; i < s.length(); i++) {
            int left = i, right = i;

            checkPalindrome(s, left, right, start_idx, max_length);

            if (s[i - 1] == s[i])
                checkPalindrome(s, left - 1, right, start_idx, max_length);
        }

        return s.substr(start_idx, max_length);
    }

    void checkPalindrome(string s, int left, int right, int& start_idx, int& max_length) {
        while (left > 0 && right < s.length() && s[left - 1] == s[right + 1]) {
            left--;
            right++;
        }

        int length = right - left + 1;
        if (length > max_length) {
            max_length = length;
            start_idx = left;
        }
    }
};

int main(int argc, char** argv) {
    Solution solution;
    string a = "babad";
    string b = "cbbd";

    string ans = solution.longestPalindrome(a);
    cout << "Input: \"" << a << "\"" << endl;
    cout << "Output: \"" << ans << "\"" << endl;
    ans = solution.longestPalindrome(b);
    cout << "Input: \"" << b << "\"" << endl;
    cout << "Output: \"" << ans << "\"" << endl;

    return 0;
}