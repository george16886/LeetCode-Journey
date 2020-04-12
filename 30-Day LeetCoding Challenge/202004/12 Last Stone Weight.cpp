#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int max1 = stones[stones.size() - 1];
            int max2 = stones[stones.size() - 2];
            int diff = max1 - max2;

            if (diff) {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(diff);
            } else {
                stones.pop_back();
                stones.pop_back();
            }
        }

        if (stones.size() == 1)
            return stones[0];
        else
            return 0;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> input = {2, 7, 4, 1, 8, 1};

    cout << "Input: [ ";
    for (const int i : input) {
        std::cout << i << " ";
    }
    cout << "]" << endl;

    int output = solution.lastStoneWeight(input);
    cout << "Output: " << output << endl;

    return 0;
}
