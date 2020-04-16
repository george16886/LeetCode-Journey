#include <iostream>
using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        
        return true;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    string input = "()";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Output: " << boolalpha << solution.checkValidString(input) << endl;

    input = "(*)";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Output: " << boolalpha << solution.checkValidString(input) << endl;

    input = "(*))";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Output: " << boolalpha << solution.checkValidString(input) << endl;

    return 0;
}
