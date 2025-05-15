class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; 
        
        int total = 0;
        int l = 0, r = n - 1;
        int left_max = 0, right_max = 0;
        
        while (l < r) {
            if (height[l] < height[r]) { // Process left side
                if (height[l] >= left_max) {
                    left_max = height[l]; // Update left max
                } else {
                    total += left_max - height[l]; // Water trapped at height[l]
                }
                l++; // Move left pointer
            } else { // Process right side
                if (height[r] >= right_max) {
                    right_max = height[r]; // Update right max
                } else {
                    total += right_max - height[r]; // Water trapped at height[r]
                }
                r--; // Move right pointer
            }
        }
        
        return total;
    }
};
