class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            int target = arr[i] * 2;
            int left = 0, right = arr.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mid != i && arr[mid] == target) {
                    return true;
                }
                if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};