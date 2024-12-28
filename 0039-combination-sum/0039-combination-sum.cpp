class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        backtrack(candidates, target, combination, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int i) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        if (target < 0 || i >= candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], curr, i);
        curr.pop_back();

        backtrack(candidates, target, curr, i + 1);
    }
};