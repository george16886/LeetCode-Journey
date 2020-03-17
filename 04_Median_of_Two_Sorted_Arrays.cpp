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

class Solution3 {
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

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);  // Make sure A2 is the shorter one.

        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;   // Try Cut 2
            int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly

            double L1 = (mid1 == 0) ? INT32_MIN : nums1[(mid1 - 1) / 2];  // Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT32_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? INT32_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == N2 * 2) ? INT32_MAX : nums2[(mid2) / 2];

            if (L1 > R2)
                lo = mid2 + 1;  // A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1)
                hi = mid2 - 1;  // A2's lower half too big; need to move C2 left.
            else
                return (max(L1, L2) + min(R1, R2)) / 2;  // Otherwise, that's the right cut.
        }
        return -1;
    }
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