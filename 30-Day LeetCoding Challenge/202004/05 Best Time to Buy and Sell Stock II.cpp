#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> a = {7, 1, 5, 3, 6, 4};
    vector<int> b = {1, 2, 3, 4, 5};
    vector<int> c = {7, 6, 4, 3, 1};
    int ans = 0;

    cout << "Input: [ ";
    for (const int i : a) {
        std::cout << i << " ";
    }
    cout << "]" << endl;
    ans = solution.maxProfit(a);
    cout << "Output: [ " << ans << endl;

    cout << "Input: [ ";
    for (const int i : b) {
        std::cout << i << " ";
    }
    cout << "]" << endl;
    ans = solution.maxProfit(b);
    cout << "Output: [ " << ans << endl;

    cout << "Input: [ ";
    for (const int i : c) {
        std::cout << i << " ";
    }
    cout << "]" << endl;
    ans = solution.maxProfit(c);
    cout << "Output: [ " << ans << endl;

    return 0;
}
