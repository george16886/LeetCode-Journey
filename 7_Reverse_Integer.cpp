class Solution {
public:
    int reverse(int x) {
        bool neg = false;
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
