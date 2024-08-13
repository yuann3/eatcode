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
    bool isBalanced(TreeNode* root) {
      return checkbalanced(root) >= 0;
    }
  private:
    int checkbalanced(TreeNode* node) {
      if (!node) return 0;

      int leftHight = checkbalanced(node->left);
      if (leftHight == -1) return -1;

      int rightHight = checkbalanced(node->right);
      if (rightHight == -1) return -1;
      
      if (abs(leftHight - rightHight) > 1) return -1;

      return max(leftHight , rightHight) + 1;
    }
};
