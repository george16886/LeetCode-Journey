#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   private:
    int diameter;

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        updateDiameter(root);
        return diameter;
    }
    int updateDiameter(TreeNode* node) {
        if (!node) return 0;
        int left = updateDiameter(node->left);
        int right = updateDiameter(node->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};

class Solution1 {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        updateDiameter(root, diameter);
        return diameter;
    }

    int updateDiameter(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int left = updateDiameter(node->left, diameter);
        int right = updateDiameter(node->right, diameter);
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
    ;

    return 0;
}