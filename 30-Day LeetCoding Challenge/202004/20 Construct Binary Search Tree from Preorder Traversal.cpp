#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
   public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder, 0, preorder.size() - 1);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;

        int left = start + 1, right = start + 1;
        while (right <= end) {
            if (preorder[right] > preorder[start])
                break;
            right++;
        }

        TreeNode* root = new TreeNode(preorder[start]);
        root->left = bstFromPreorder(preorder, left, right - 1);
        root->right = bstFromPreorder(preorder, right, end);

        return root;
    }
};

class Solution {
   public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (!n) return NULL;

        vector<int> left, right;
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < n; i++) {
            if (preorder[i] > root->val)
                right.push_back(preorder[i]);
            else
                left.push_back(preorder[i]);
        }

        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);

        return root;
    }
};

// Function to print a tree by level-order traversal
void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main(int argc, char** argv) {
    Solution solution;

    vector<int> input = {8, 5, 1, 7, 10, 12};
    cout << "Input: [ ";
    for (auto i : input)
        cout << i << " ";
    cout << "]" << endl;
    TreeNode* output = solution.bstFromPreorder(input);
    cout << "Output: [ ";
    levelOrderTraversal(output);
    cout << "]" << endl;

    return 0;
}
