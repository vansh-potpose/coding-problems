class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        int hIndex = 0;

        for (int i = 0; i < n; i++) {
            int remainingPapers = n - i; // Papers that have at least citations[i] citations
            if (citations[i] >= remainingPapers) { // If this citation count is enough for h-index
                hIndex = remainingPapers; 
                break; // Since the array is sorted, further values will only be smaller or equal
            }
        } 
        return hIndex;
    }
};