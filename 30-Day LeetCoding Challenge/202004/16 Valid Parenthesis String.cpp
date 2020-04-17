#include <iostream>
#include <stack>
using namespace std;

class Solution1 {
   public:
    bool checkValidString(string s) {
        stack<int> left, star;
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

class Solution {
   public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '*')
                left++;
            else
                left--;

            int j = s.size() - 1 - i;
            if (s[j] == ')' || s[j] == '*')
                right++;
            else
                right--;

            if (left < 0 || right < 0)
                return false;
        }
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
