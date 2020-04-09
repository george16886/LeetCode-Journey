#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        return false;
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