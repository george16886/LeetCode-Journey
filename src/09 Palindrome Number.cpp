class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = x;
        int ans = 0;
        int ans1;
        while (div > 0) {
            ans = ans * 10 + div % 10;
            div = div / 10;
        }
        if (ans > 2147483647) return false;
        ans1 = ans - x;
        if (ans1 == 0) return true;
        else return false;
        
    }
};
