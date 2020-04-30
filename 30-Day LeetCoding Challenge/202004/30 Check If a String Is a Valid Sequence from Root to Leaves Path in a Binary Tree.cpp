#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        return isValidSequence(root, arr, 0);
    }

    bool isValidSequence(TreeNode *root, vector<int> &arr, int i) {
        if (!root || (i >= arr.size()) || (root->val != arr[i]))
            return false;

        if ((i == arr.size() - 1) && !root->left && !root->right)
            return true;

        return isValidSequence(root->left, arr, i + 1) || isValidSequence(root->right, arr, i + 1);
    }
};

int main(int argc, char **argv) {
    Solution solution;

    // Make the nodes
    TreeNode root(0);
    TreeNode leftChild(1);
    TreeNode rightChild(0);
    TreeNode leftChild_l(0);
    TreeNode leftChild_lr(1);
    TreeNode leftChild_r(1);
    TreeNode leftChild_rl(0);
    TreeNode leftChild_rr(0);
    TreeNode rightChild_l(0);

    // Connect nodes
    root.left = &leftChild;
    leftChild.left = &leftChild_l;
    leftChild_l.right = &leftChild_lr;
    leftChild.right = &leftChild_r;
    leftChild_r.left = &leftChild_rl;
    leftChild_r.right = &leftChild_rr;
    root.right = &rightChild;
    rightChild.left = &rightChild_l;

    vector<int> arr = {0, 1, 0, 1};
    cout << "Output: " << boolalpha << solution.isValidSequence(&root, arr) << endl
         << endl;

    arr = {0, 0, 1};
    cout << "Output: " << boolalpha << solution.isValidSequence(&root, arr) << endl
         << endl;

    arr = {0, 1, 1};
    cout << "Output: " << boolalpha << solution.isValidSequence(&root, arr) << endl
         << endl;

    return 0;
}