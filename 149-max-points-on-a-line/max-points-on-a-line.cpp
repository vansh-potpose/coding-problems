class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int maxAns = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopeMap;
            int duplicates = 1;
            int vertical = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;  // same point
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    // Keep slope direction consistent
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    slopeMap[{dy, dx}]++;
                    localMax = max(localMax, slopeMap[{dy, dx}]);
                }
            }

            maxAns = max(maxAns, localMax + duplicates);
        }

        return maxAns;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
