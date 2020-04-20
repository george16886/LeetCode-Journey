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

class Solution {
   public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
    }
};

// Level-order traversal
void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);  // 把root作為level-order traversal之起點推進queue中

    while (!q.empty()) {                // 若queue不是空的, 表示還有node沒有visiting
        TreeNode* current = q.front();  // 取出先進入queue的node
        q.pop();
        cout << current->val << " ";  // 進行visiting

        if (current->left != NULL)  // 若leftchild有資料, 將其推進queue
            q.push(current->left);

        if (current->right != NULL)  // 若rightchild有資料, 將其推進queue
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
