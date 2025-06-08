class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] >= currHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }

        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())return 0;

        int maxArea=0;
        int m = matrix.size(),n= matrix[0].size();
        vector<int> heights(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    heights[j]+=1;
                else
                    heights[j]=0;
            }
            maxArea=max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};