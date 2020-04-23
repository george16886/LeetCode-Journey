#include <iostream>
using namespace std;

<<<<<<< HEAD
class Solution1 {
   public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = m, i = m + 1;
        while (i <= n)
            ans &= i++;

        return ans;
    }
};

class Solution2 {
   public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            cnt++;
        }

        return m << cnt;
    }
};

class Solution {
   public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m)
            n &= n--;

        return n;
=======
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 1;
        for (int i = m; i <= n; i++)
            ans &= i;

        return ans;
>>>>>>> 7bcafb6c370ef4fffaca6c4d1919d4123a48add8
    }
};

int main(int argc, char** argv) {
    Solution solution;
<<<<<<< HEAD

    int a = 5, b = 7;
    cout << "Input: [" << a << "," << b << "]" << endl;
    cout << "Output: " << solution.rangeBitwiseAnd(a, b) << endl
         << endl;

    a = 0;
    b = 1;
    cout << "Input: [" << a << "," << b << "]" << endl;
    cout << "Output: " << solution.rangeBitwiseAnd(a, b) << endl
         << endl;
=======
    
    int a = 5, b = 7;
    cout << "Input: [" << a << "," << b << "]" << endl;
    cout << "Output: " << solution.rangeBitwiseAnd(a, b) << endl << endl;

    a = 0; b = 1;
    cout << "Input: [" << a << "," << b << "]" << endl;
    cout << "Output: " << solution.rangeBitwiseAnd(a, b) << endl << endl;
>>>>>>> 7bcafb6c370ef4fffaca6c4d1919d4123a48add8

    return 0;
}
