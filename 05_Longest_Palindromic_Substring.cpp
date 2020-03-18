#include <iostream>
#include <string>
using namespace std;

class Solution1 {
   public:
    string longestPalindrome(string s) {
        int max_length = 1;
        int start_idx = 0;

        for (int i = 1; i < s.length(); i++) {
            checkPalindrome(s, i, i, start_idx, max_length);

            if (s[i] == s[i - 1])
                checkPalindrome(s, i - 1, i, start_idx, max_length);
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
class Solution2 {
   public:
    string longestPalindrome(string s) {
        int max_length = 1;
        int start_idx = 0;

        for (int i = 0; i < s.length(); i++) {
            checkPalindrome(s, i, i, start_idx, max_length);
            checkPalindrome(s, i, i + 1, start_idx, max_length);
        }

        return s.substr(start_idx, max_length);
    }

    void checkPalindrome(string s, int left, int right, int& start_idx, int& max_length) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        int length = right - left + 1 - 2;
        if (length > max_length) {
            max_length = length;
            start_idx = left + 1;
        }
    }
};

class Solution {
   public:
    string longestPalindrome(string s) {
        int max_length = 1;
        int start_idx = 0;
        int n = s.length();

        if (!n) return s;
        bool isPalindrome[n][n] = {false};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j)
                    isPalindrome[i][j] = true;
                if ((i == j + 1) && (s[i] == s[j]))
                    isPalindrome[i][j] = true;
                if ((i > j + 1) && (s[i] == s[j]) && isPalindrome[i - 1][j + 1])
                    isPalindrome[i][j] = true;

                int length = i - j + 1;
                // cout << "(" << i << ", " << j << "): isPalindrome = " << isPalindrome[i][j] << ", length = " << length << endl;
                if (isPalindrome[i][j] && (length > max_length)) {
                    max_length = length;
                    start_idx = j;
                }
            }
        }

        return s.substr(start_idx, max_length);
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