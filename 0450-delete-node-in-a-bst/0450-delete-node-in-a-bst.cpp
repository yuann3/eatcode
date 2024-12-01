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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while (cur != nullptr && cur->val != key) {
            pre = cur;
            if (key < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        if (cur == nullptr) {
            return root;
        }

        if (cur->left == nullptr || cur->right == nullptr) {
            TreeNode* child = (cur->left != nullptr) ? cur->left : cur->right;

            if (pre == nullptr) {
                return child;
            }

            if (pre->left == cur) {
                pre->left = child;
            } else {
                pre->right = child;
            }

            delete cur;
        } else {
            TreeNode* succ = cur->right;
            TreeNode* succParent = cur;

            while (succ->left != nullptr) {
                succParent = succ;
                succ = succ->left;
            }

            cur->val = succ->val;

            if (succParent->left == succ) {
                succParent->left = succ->right;
            } else {
                succParent->right = succ->right;
            }

            delete succ;
        }

        return root;
    }
};