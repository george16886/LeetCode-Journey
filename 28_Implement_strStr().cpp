class Solution {
public:
    int strStr(string haystack, string needle) {
//        return haystack.find(needle, 0);
        
        int len = haystack.length();
        int len2 = needle.length();
        if (len == 0 && len2 == 0) return 0;
        else if (len == 0) return -1;
        else {
            for (int i = 0; i <= len - len2; i++) {
                if (equal(haystack.substr(i, len2), needle, len2)) return i;
            }
            return -1;
        }
    }
    
    bool equal(string s1, string s2, int len2) {
        int a = 0;
        for (int j = 0; j < len2; j++) {
            if (s1[j] == s2[j]) a++;
        }
        if (a == len2) return true;
        else return false;
    }

};
