#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, int> hmap;
        while (n != 1) {
            if (hmap[n])
                return false;
            hmap[n]++;

            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            n = sum;
        }

        if (n == 1)
            return true;
        else
            return false;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    int input = 19;

    bool ans = solution.isHappy(input);
    cout << "Input: " << input << endl;
    if (ans)
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}
