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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            vector<int> level;
            int size = queue.size();

            for (int i = queue.size(); i > 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node) {
                    level.push_back(node->val);
                    queue.push(node->left);
                    queue.push(node->right);
                }
            }
            if (!level.empty()) {
                result.push_back(level);
            }
        }
        return result;
    }
};