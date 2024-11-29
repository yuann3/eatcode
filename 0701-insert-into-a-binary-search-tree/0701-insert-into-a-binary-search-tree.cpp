/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode *cur = root, *prev = nullptr;

        while (cur != nullptr) {
            if (cur->val == val) {
                return root;
            }

            prev = cur;

            if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        TreeNode *node = new TreeNode(val);
        if (prev->val < val) {
            prev->right = node;
        } else {
            prev->left = node;
        }

        return root;
    }
};