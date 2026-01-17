class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxSide = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate the intersection boundaries
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                // Calculate width and height of the intersection
                long long width = x2 - x1;
                long long height = y2 - y1;

                // Check if they actually intersect
                if (width > 0 && height > 0) {
                    long long currentSide = min(width, height);
                    maxSide = max(maxSide, currentSide);
                }
            }
        }

        return maxSide * maxSide;
    }
};