class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 2e9;
        double high = 0;

        for (auto& s : squares) {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double targetArea = totalArea / 2.0;

        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2.0;
            double currentArea = 0;

            for (auto& s : squares) {
                double y = s[1];
                double l = s[2];
                double h_below = max(0.0, min(l, mid - y));
                currentArea += h_below * l;
            }

            if (currentArea < targetArea) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};