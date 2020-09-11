class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> tmp(1,1);
        int ans = 0;
        int level = 1;
        while (!tmp.empty()) {
            tmp.clear();
            for (int i = 0; i < height.size(); i++) {
                if (height.at(i) >= level) {
                    tmp.push_back(i);
                }
            }
            if (!tmp.empty()) {
                for (int i = tmp.at(0); i < tmp.at(tmp.size() - 1) ; i++) {
                    if (height.at(i) < level) {
                        ans++;
                    }
                }
            }
            level++;
        }
        return ans;
    }
};
