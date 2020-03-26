#include <iostream>

class Solution {
   public:
    int reverse(int x) {
        bool neg = false;
        if (x < -2147483647) return 0;
        if (x < 0) {
            x = -x;
            neg = true;
        }

        int div = x;
        int ans = 0;
        while (div > 0) {
            if (ans > 214748364) return 0;
            ans = ans * 10 + div % 10;
            div = div / 10;
        }

        return (neg) ? -ans : ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    int a = 123;
    int ans = solution.reverse(a);
    std::cout << "Input: " << a << std::endl;
    std::cout << "Output: " << ans << std::endl;

    a = -123;
    ans = solution.reverse(a);
    std::cout << "Input: " << a << std::endl;
    std::cout << "Output: " << ans << std::endl;

    a = 120;
    ans = solution.reverse(a);
    std::cout << "Input: " << a << std::endl;
    std::cout << "Output: " << ans << std::endl;

    return 0;
}
