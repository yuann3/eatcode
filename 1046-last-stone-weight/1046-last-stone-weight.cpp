class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i : stones) {
            maxHeap.push(i);
        }

        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (y < x) {
                maxHeap.push(x - y);
            }
        }

        maxHeap.push(0);
        return maxHeap.top();
    }
};