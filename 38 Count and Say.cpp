class Solution { //1, 11, 21, 1211, 111221, ...
public:
    string countAndSay(int n) {
        string ans = "1";
        if (n == 1) return ans;
        else {
            ans = "1" + ans;
            for (int j = 2; j < n; j++) {
                string result;
                int cnt = 1;
                for (int i = 0; i < ans.length() - 1; i++) {
                    if (ans.at(i + 1) == ans.at(i)) {
                        cnt++;
                    } 
                    else {
                        result = result + std::to_string(cnt) + ans.at(i);
                        cnt = 1;
                    }
                }
                result = result + std::to_string(cnt) + ans.at(ans.length() - 1);
                ans = result;
            }
            return ans; 
        }
    }
};
