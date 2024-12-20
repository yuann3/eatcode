/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverseDFS(TreeNode* left, TreeNode* right, bool isOdd) {
        if (!left || !right)
            return;

        if (isOdd) {
            swap(left->val, right->val);
        }

        traverseDFS(left->left, right->right, !isOdd);
        traverseDFS(left->right, right->left, !isOdd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;
        traverseDFS(root->left, root->right, true);
        return root;
    }
};