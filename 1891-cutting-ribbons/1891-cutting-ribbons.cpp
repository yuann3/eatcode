class Solution {
public:
    long long countRibbons(vector<int>& ribbons, int length) {
        if (length == 0)
            return LLONG_MAX;
        long long count = 0;
        for (int ribbon : ribbons) {
            count += ribbon / length;
            if (count > INT_MAX)
                return count;
        }
        return count;
    }

    int maxLength(vector<int>& ribbons, int k) {
        if (k == 0)
            return 0;

        int maxRibbon = 0;
        long long totalLength = 0;
        for (int ribbon : ribbons) {
            maxRibbon = max(maxRibbon, ribbon);
            totalLength += ribbon;
        }

        if (totalLength < k)
            return 0;

        long long left = 1;
        long long right = maxRibbon;
        long long result = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = countRibbons(ribbons, mid);

            if (count >= k) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
