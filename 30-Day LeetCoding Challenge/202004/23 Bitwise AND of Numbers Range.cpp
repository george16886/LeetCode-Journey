#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 1;
        for (int i = m; i <= n; i++)
            ans &= i;

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    
    int a = 5, b = 7;
    cout << "Input: [" << a << "," << b << "]" << endl;
    cout << "Output: " << solution.rangeBitwiseAnd(a, b) << endl << endl;

    a = 0; b = 1;
    cout << "Input: [" << a << "," << b << "]" << endl;
    cout << "Output: " << solution.rangeBitwiseAnd(a, b) << endl << endl;

    return 0;
}
