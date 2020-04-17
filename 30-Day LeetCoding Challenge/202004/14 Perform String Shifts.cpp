#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for (auto instruction : shift) {
            bool direction = instruction[0];
            int amount = instruction[1];
            for (int i = 0; i < amount; i++) {
                if (direction)
                    s = s[s.size() - 1] + s.substr(0, s.size() - 1);
                else
                    s = s.substr(1, s.size() - 1) + s[0];
            }
        }

        return s;
    }
};

class Solution {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int final = 0;
        for (auto instruction : shift) {
            bool direction = instruction[0];
            int amount = instruction[1];
            final += (direction) ? amount : -amount;
        }

        for (int i = 0; i < abs(final); i++) {
            if (final > 0)
                s = s[s.size() - 1] + s.substr(0, s.size() - 1);
            else
                s = s.substr(1, s.size() - 1) + s[0];
        }

        return s;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    string s = "abc";
    vector<vector<int>> shift = {{0, 1}, {1, 2}};
    cout << "Input: s = \"" << s << "\", shift = { ";
    for (auto s : shift) {
        cout << "[ ";
        for (auto i : s)
            cout << i << " ";
        cout << "] ";
    }
    cout << "}\nOutput: \"" << solution.stringShift(s, shift) << "\"\n"
         << endl;

    s = "abcdefg";
    shift = {{1, 1}, {1, 1}, {0, 2}, {1, 3}};
    cout << "Input: s = \"" << s << "\", shift = { ";
    for (auto s : shift) {
        cout << "[ ";
        for (auto i : s)
            cout << i << " ";
        cout << "] ";
    }
    cout << "}\nOutput: \"" << solution.stringShift(s, shift) << "\"\n"
         << endl;

    return 0;
}
