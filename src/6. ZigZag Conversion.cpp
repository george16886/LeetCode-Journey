#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution1 {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        int length = s.length();
        int jump = numRows * 2 - 2;
        int loop = length / jump;

        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= loop; j++) {
                int index = j * jump + i;
                if (index < length)
                    ans += s[index];

                index += jump - 2 * i;
                if (i > 0 && i < numRows - 1 && index < length)
                    ans += s[index];
            }
        }

        return ans;
    }
};

class Solution2 {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        int length = s.length();
        int jump = numRows * 2 - 2;

        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < length; j += jump) {
                ans += s[j];

                int index = j + jump - 2 * i;
                if (i > 0 && i < numRows - 1 && index < length)
                    ans += s[index];
            }
        }

        return ans;
    }
};

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        int length = s.length();
        int index = 0;

        vector<string> v(numRows);
        while (index < length) {
            for (int row = 0; row < numRows && index < length; row++) {
                v[row] += s[index];
                index++;
            }
            for (int row = numRows - 2; row > 0 && index < length; row--) {
                v[row] += s[index];
                index++;
            }
        }

        string ans;
        for (auto& substr : v)
            ans += substr;

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    string a = "PAYPALISHIRING";

    string ans = solution.convert(a, 3);
    cout << "Input: s = \"" << a << "\", numRows = 3" << endl;
    cout << "Output: \"" << ans << "\"" << endl;
    ans = solution.convert(a, 4);
    cout << "Input: s = \"" << a << "\", numRows = 4" << endl;
    cout << "Output: \"" << ans << "\"" << endl;

    return 0;
}