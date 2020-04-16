#include <iostream>
#include <stack>
using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == '*')
                star.push(i);
            else if (s[i] == ')') {
                if (left.empty() && star.empty())
                    return false;
                else if (!left.empty())
                    left.pop();
                else if (!star.empty())
                    star.pop();
            }
        }

        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top())
                return false;
            else {
                left.pop();
                star.pop();
            }
        }

        return left.empty();
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
