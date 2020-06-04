#include <iostream>
#include <string>
using namespace std;

class Solution1 {
   public:
    bool backspaceCompare(string S, string T) {
        string s = "";
        for (char c : S) {
            if (c == '#') {
                if (s.size())
                    s.pop_back();
            } else
                s.push_back(c);
        }

        string t = "";
        for (char c : T) {
            if (c == '#') {
                if (t.size())
                    t.pop_back();
            } else
                t.push_back(c);
        }

        return (s == t);
    }
};

class Solution2 {
   public:
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";
        for (char c : S) {
            (c == '#') ? (s.size() > 0) ? s.pop_back() : void() : s.push_back(c);
        }
        for (char c : T) {
            (c == '#') ? (t.size() > 0) ? t.pop_back() : void() : t.push_back(c);
        }

        return (s == t);
    }
};

class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        int sIdx = S.size() - 1, tIdx = T.size() - 1;
        int sCnt = 0, tCnt = 0;
        while (sIdx >= 0 || tIdx >= 0) {
            while (sIdx >= 0 && (S[sIdx] == '#' || sCnt > 0)) {
                if (S[sIdx] == '#')
                    sCnt++;
                else
                    sCnt--;

                sIdx--;
            }

            while (tIdx >= 0 && (T[tIdx] == '#' || tCnt > 0)) {
                if (T[tIdx] == '#')
                    tCnt++;
                else
                    tCnt--;

                tIdx--;
            }

            if (sIdx < 0 || tIdx < 0)
                return (sIdx == tIdx);

            if (S[sIdx] == T[tIdx]) {
                sIdx--;
                tIdx--;
            } else
                return false;
        }

        return (sIdx == tIdx);
    }
};

int main(int argc, char** argv) {
    Solution solution;
    string S, T;
    bool output;

    cout << "Example 1:" << endl;
    S = "ab#c";
    T = "ad#c";
    output = solution.backspaceCompare(S, T);
    cout << "Input: "
         << "S = \"" << S << "\", T = \"" << T << "\"" << endl;
    cout << "Output: " << boolalpha << output << endl;

    cout << endl;
    cout << "Example 2:" << endl;
    S = "ab##";
    T = "c#d#";
    output = solution.backspaceCompare(S, T);
    cout << "Input: "
         << "S = \"" << S << "\", T = \"" << T << "\"" << endl;
    cout << "Output: " << boolalpha << output << endl;

    cout << endl;
    cout << "Example 3:" << endl;
    S = "a##c";
    T = "#a#c";
    output = solution.backspaceCompare(S, T);
    cout << "Input: "
         << "S = \"" << S << "\", T = \"" << T << "\"" << endl;
    cout << "Output: " << boolalpha << output << endl;

    cout << endl;
    cout << "Example 4:" << endl;
    S = "a#c";
    T = "b";
    output = solution.backspaceCompare(S, T);
    cout << "Input: "
         << "S = \"" << S << "\", T = \"" << T << "\"" << endl;
    cout << "Output: " << boolalpha << output << endl;

    return 0;
}