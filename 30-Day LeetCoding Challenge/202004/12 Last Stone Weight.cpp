#include <algorithm>
#include <iostream>
#include <queue>
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

class Solution2 {
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

class Solution3 {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> priority_q;
        for (int stone : stones) priority_q.push(stone);

        while (priority_q.size() > 1) {
            int max1 = priority_q.top();
            priority_q.pop();
            int max2 = priority_q.top();
            priority_q.pop();
            int v = abs(max1 - max2);
            if (v) priority_q.push(v);
        }

        return (priority_q.size()) ? priority_q.top() : 0;
    }
};

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> priority_q(begin(stones), end(stones));

        while (priority_q.size() > 1) {
            int max1 = priority_q.top();
            priority_q.pop();
            int max2 = priority_q.top();
            priority_q.pop();
            if (max1 - max2) priority_q.push(max1 - max2);
        }

        return (priority_q.size()) ? priority_q.top() : 0;
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
