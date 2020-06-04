#include <iostream>
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
    int maxPathSum(TreeNode *root) {
        int sum = root->val;
        PathSum(root, sum);
        return sum;
    }

    int PathSum(TreeNode *node, int &sum) {
        if (!node) return 0;

        int left = max(PathSum(node->left, sum), 0);
        int right = max(PathSum(node->right, sum), 0);
        sum = max(sum, left + node->val + right);

        return max(left, right) + node->val;
    }
};

int main(int argc, char **argv) {
    Solution solution;

    // Make the nodes
    TreeNode root(1);
    TreeNode leftChild(2);
    TreeNode rightChild(3);

    // Connect nodes
    root.left = &leftChild;
    root.right = &rightChild;

    cout << "Output: " << solution.maxPathSum(&root) << endl
         << endl;

    // Make the nodes
    TreeNode root2(-10);
    TreeNode leftChild2(9);
    TreeNode rightChild2(20);
    TreeNode rightChild2_l(15);
    TreeNode rightChild2_r(7);

    // Connect nodes
    rightChild2.left = &rightChild2_l;
    rightChild2.right = &rightChild2_r;
    root2.left = &leftChild2;
    root2.right = &rightChild2;

    cout << "Output: " << solution.maxPathSum(&root2) << endl
         << endl;

    // Make the nodes
    TreeNode root3(1);
    TreeNode leftChild3(-2);
    TreeNode rightChild3(3);

    // Connect nodes
    root3.left = &leftChild3;
    root3.right = &rightChild3;

    cout << "Output: " << solution.maxPathSum(&root3) << endl
         << endl;

    return 0;
}