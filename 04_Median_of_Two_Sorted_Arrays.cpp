#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        bool odd = (m + n) % 2;
        int x = (m + n) / 2;

        vector<int> merge;
        int a = 0, b = 0;
        double ans = 0;

        // if (m == 0 && n == 0) {
        //     ans = 0;
        // } else if (n == 0) {
        if (n == 0) {
            ans = (odd) ? nums1.at(x) : (double)(nums1.at(x - 1) + nums1.at(x)) / 2;
        } else if (m == 0) {
            ans = (odd) ? nums2.at(x) : (double)(nums2.at(x - 1) + nums2.at(x)) / 2;
        } else {
            for (int i = 0; i <= x; i++) {
                if (nums1.at(a) < nums2.at(b)) {
                    merge.push_back(nums1.at(a));
                    if (a < m - 1) {
                        a++;
                    } else {
                        nums1.at(a) = INT32_MAX;
                    }
                } else {
                    merge.push_back(nums2.at(b));
                    if (b < n - 1) {
                        b++;
                    } else {
                        nums2.at(b) = INT32_MAX;
                    }
                }
            }
            ans = (odd) ? merge.at(x) : (double)(merge.at(x - 1) + merge.at(x)) / 2;
        }

        return ans;
    }
};

class Solution2 {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int x1 = (m + n + 1) / 2;
        int x2 = (m + n + 2) / 2;

        vector<int> merge;
        int a = 0, b = 0;
        double ans = 0;

        // if (m == 0 && n == 0) {
        //     ans = 0;
        // } else if (n == 0) {
        if (n == 0) {
            ans = (nums1.at(x1 - 1) + nums1.at(x2 - 1)) / 2.0;
        } else if (m == 0) {
            ans = (nums2.at(x1 - 1) + nums2.at(x2 - 1)) / 2.0;
        } else {
            for (int i = 0; i <= x2; i++) {
                if (nums1.at(a) < nums2.at(b)) {
                    merge.push_back(nums1.at(a));
                    if (a < m - 1) {
                        a++;
                    } else {
                        nums1.at(a) = nums2.at(n - 1) + 1;
                    }
                } else {
                    merge.push_back(nums2.at(b));
                    if (b < n - 1) {
                        b++;
                    } else {
                        nums2.at(b) = nums1.at(m - 1) + 1;
                    }
                }
            }
            ans = (merge.at(x1 - 1) + merge.at(x2 - 1)) / 2.0;
        }

        return ans;
    }
};

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        int x1 = (m + n + 1) / 2;
        int x2 = (m + n + 2) / 2;

        return (findMedian(nums1, 0, nums2, 0, x1) + findMedian(nums1, 0, nums2, 0, x2)) / 2.0;
    }

    int findMedian(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i > m - 1)
            return nums2[j + k - 1];
        if (j > n - 1)
            return nums1[i + k - 1];

        if (k == 1)
            return min(nums1[i], nums2[j]);

        int i_upd = i + k / 2;
        int j_upd = j + k / 2;

        if (i_upd - 1 > m - 1)
            return findMedian(nums1, i, nums2, j_upd, k - k / 2);
        if (j_upd - 1 > n - 1)
            return findMedian(nums1, i_upd, nums2, j, k - k / 2);

        if (nums1[i_upd - 1] < nums2[j_upd - 1])
            return findMedian(nums1, i_upd, nums2, j, k - k / 2);
        else
            return findMedian(nums1, i, nums2, j_upd, k - k / 2);
    }

    int m, n;
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    vector<int> c = {1, 2};
    vector<int> d = {3, 4};

    double ans = solution.findMedianSortedArrays(a, b);
    cout << "The median is: " << ans << endl;
    ans = solution.findMedianSortedArrays(c, d);
    cout << "The median is: " << ans << endl;

    return 0;
}