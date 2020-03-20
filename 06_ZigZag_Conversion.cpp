#include <iostream>
#include <string>
using namespace std;

class Solution {
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
                int idx = j * jump + i;
                if (idx < length)
                    ans += s[idx];

                idx += jump - 2 * i;
                if (i > 0 && i < numRows - 1 && idx < length)
                    ans += s[idx];
            }
        }

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