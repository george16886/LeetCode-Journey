#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
   private:
    int diameter;

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
    
    int maxDepth(TreeNode* node) {
        if (!node) return 0;
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }

    int maxDepth(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int left = maxDepth(node->left, diameter);
        int right = maxDepth(node->right, diameter);
        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    // Make the nodes
    TreeNode root(1);
    TreeNode leftChild(2);
    TreeNode leftChild4(4);
    TreeNode leftChild5(5);
    TreeNode rightChild(3);

    // Connect nodes
    leftChild.left = &leftChild4;
    leftChild.right = &leftChild5;
    root.left = &leftChild;
    root.right = &rightChild;

    cout << "Output: " << solution.diameterOfBinaryTree(&root) << endl;

    return 0;
}