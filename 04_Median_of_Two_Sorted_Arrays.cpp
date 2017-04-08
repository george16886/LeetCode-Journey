class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        bool odd = (m + n) % 2;
        int x = ceil((m + n) / 2);
        vector <int> merge;
        int a = 0, b = 0;
        double ans = 0;
        if (m == 0 && n == 0) {
            ans = 0;
        }
        else if (n == 0) {
            ans = (odd)? nums1.at(x) : (double)(nums1.at(x - 1) + nums1.at(x)) / 2; 
        }
        else if (m == 0) {
            ans = (odd)? nums2.at(x) : (double)(nums2.at(x - 1) + nums2.at(x)) / 2; 
        }
        else {
            for (int i = 0; i <= x; i++) {
                if (nums1.at(a) < nums2.at(b)) {
                    merge.push_back(nums1.at(a));
                    if (a < m - 1) {
                        a++;
                    }
                    else {
                        nums1.at(a) = nums2.at(n - 1) + 1;
                    }
                }
                else {
                    merge.push_back(nums2.at(b));
                    if (b < n - 1) {
                        b++;
                    }
                    else {
                        nums2.at(b) = nums1.at(m - 1) + 1;
                    }
                }
            }
            ans = (odd)? merge.at(x) : (double)(merge.at(x - 1) + merge.at(x)) / 2;  
        }
        return ans;
    }
};
