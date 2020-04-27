#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> hmap;
        for (const int i : arr) {
            hmap[i]++;
        }

        int ans = 0;
        for (const int i : arr) {
            if (hmap.count(i + 1))
                ans += hmap.count(i);
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 1, 3, 3, 5, 5, 7, 7};
    vector<int> c = {1, 3, 2, 3, 5, 0};
    vector<int> d = {1, 1, 2, 2};
    int ans = 0;

    cout << "Example 1:" << endl;
    cout << "Input: [ ";
    for (const int i : a)
        std::cout << i << " ";
    cout << "]" << endl;
    ans = solution.countElements(a);
    cout << "Output: " << ans << endl;

    cout << endl;
    cout << "Example 2:" << endl;
    cout << "Input: [ ";
    for (const int i : b)
        std::cout << i << " ";
    cout << "]" << endl;
    ans = solution.countElements(b);
    cout << "Output: " << ans << endl;

    cout << endl;
    cout << "Example 3:" << endl;
    cout << "Input: [ ";
    for (const int i : c)
        std::cout << i << " ";
    cout << "]" << endl;
    ans = solution.countElements(c);
    cout << "Output: " << ans << endl;

    cout << endl;
    cout << "Example 4:" << endl;
    cout << "Input: [ ";
    for (const int i : d)
        std::cout << i << " ";
    cout << "]" << endl;
    ans = solution.countElements(d);
    cout << "Output: " << ans << endl;

    return 0;
}
