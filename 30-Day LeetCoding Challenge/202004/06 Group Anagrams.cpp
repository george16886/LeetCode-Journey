#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        for (string str : strs) {
            string category;
            // int count[26] = {};
            vector<int> count(26);
            for (char c : str) {
                count[c - 'a']++;
                // cout << c << ": " << c - 'a' << endl;
            }

            for (int i = 0; i < 26; ++i) {
                if (count[i]) {
                    // category += to_string(count[i]) + string(1, i + 'a');
                    category += to_string(count[i]) + to_string(i);
                }
            }
            // cout << category << endl;

            hmap[category].push_back(str);
        }

        vector<vector<string>> output;
        for (auto h : hmap) {
            // cout << h.first << endl;
            // cout << h.second[0] << endl;
            output.push_back(h.second);
        }

        return output;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output;

    cout << "Input: [ ";
    // for (const string s : input)
    for (const auto s : input)
        std::cout << s << " ";
    cout << "]" << endl;

    output = solution.groupAnagrams(input);
    cout << "output:" << endl
         << "[ " << endl;
    // for (const vector<string> sub : output)
    //     for (const string s : sub)
    for (const auto sub : output) {
        cout << "  [ ";
        for (const auto s : sub)
            std::cout << "\"" << s << "\" ";
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}
