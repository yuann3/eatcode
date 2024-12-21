class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int result = 0;

        function<long long(int, int)> dfs = [&](int node,
                                                int parent) -> long long {
            long long sum = values[node];

            for (int child : adj[node]) {
                if (child != parent) {
                    long long childSum = dfs(child, node);
                    if (childSum % k == 0) {
                        result++;
                    } else {
                        sum += childSum;
                    }
                }
            }

            return sum;
        };

        long long totalSum = dfs(0, -1);
        if (totalSum % k == 0) {
            result++;
        }

        return result;
    }
};