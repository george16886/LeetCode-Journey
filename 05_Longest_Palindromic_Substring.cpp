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

class Solution3 {
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

class Solution {  // Manacher Algorithm
   public:
    string longestPalindrome(string s) {
        string t = "$#";  // '$' is prepended to avoid boundary checking.
                          // '#' is interleaved inserted to unify processing of palindromes with even or odd length.
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }

        int P[t.size()] = {0};  // The expansion length to the left or to the right.
        int c = 0;              // The center of palindromic substring that reaches the rightest side of P.
        int r = 0;              // The rightest index (right boundary) of palindromic substring in P.
        int cWithMaxLen = 0;    // Center of longest palindromic substring in P.
        int maxLen = 0;         // Length of longest palindromic substring in P.

        for (int i = 1; i < t.size(); ++i) {
            int mirror = (2 * c) - i;  // The mirror index of i.

            // See if the mirror of i is expanding beyond the left boundary of current longest palindrome at center c.
            // If it is, then take r - i as P[i]; else take P[mirror] as P[i].
            P[i] = (i < r) ? min(P[mirror], r - i) : 1;

            // Attempt to expand palindrome centered at i.
            while (t[i + P[i]] == t[i - P[i]]) ++P[i];

            // Check if the expanded palindrome at i is expanding beyond the right boundary of current longest palindrome at center c.
            // If it is, the new center is i.
            if (i + P[i] > r) {
                r = i + P[i];
                c = i;
            }

            // Update max length and the corresponding center.
            if (P[i] > maxLen) {
                maxLen = P[i] - 1;
                cWithMaxLen = i;
            }
        }

        return s.substr((cWithMaxLen - maxLen) / 2, maxLen);
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