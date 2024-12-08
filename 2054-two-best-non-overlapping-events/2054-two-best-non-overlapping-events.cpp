class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // sort by start time
        sort(events.begin(), events.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int maxVal = 0;
        int maxSum = 0;

        for (const auto& event : events) {
            int start = event[0], end = event[1], value = event[2];

            while (!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // combining current event with best previous non-overlapping event
            maxSum = max(maxSum, value + maxVal);

            pq.push({end, value});
        }
        return maxSum;
    }
};