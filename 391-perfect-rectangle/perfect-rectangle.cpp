#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> corners;
        long long area = 0;
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;

        for (auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];

            // Update bounding box
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // Accumulate area
            area += 1LL * (x2 - x1) * (y2 - y1);

            // Process corners
            vector<pair<int, int>> points = {
                {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}
            };
            for (auto& p : points) {
                if (!corners.insert(p).second) {
                    corners.erase(p); // remove if already exists (even count)
                }
            }
        }

        // Check if total area matches bounding box area
        long long expectedArea = 1LL * (maxX - minX) * (maxY - minY);
        if (area != expectedArea) return false;

        // Final 4 corners should be the bounding rectangle
        if (corners.size() != 4) return false;
        if (!corners.count({minX, minY})) return false;
        if (!corners.count({minX, maxY})) return false;
        if (!corners.count({maxX, minY})) return false;
        if (!corners.count({maxX, maxY})) return false;

        return true;
    }
};
