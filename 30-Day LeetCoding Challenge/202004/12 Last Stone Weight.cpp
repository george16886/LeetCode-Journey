#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int diff = stones[stones.size() - 1] - stones[stones.size() - 2];
            stones.erase(stones.end() - 2, stones.end());

            if (diff)
                stones.push_back(diff);
        }

        return (stones.size()) ? stones[0] : 0;
    }
};

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int max = stones[stones.size() - 1];
            stones.pop_back();
            int diff = max - stones[stones.size() - 1];
            stones.pop_back();

            if (diff)
                stones.push_back(diff);
        }

        return (stones.size()) ? stones[0] : 0;
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
