#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {

        
        return root->left->val;
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

    cout << "Output: " << solution.diameterOfBinaryTree(&root) << endl;;

    return 0;
}