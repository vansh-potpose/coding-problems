class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int n=points.size();
        double maxArea=0;
        for(int i=0; i<n-2; i++){
            const int a0=points[i][0], a1=points[i][1];
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    double area=0.5*((points[j][0]-a0)*(points[k][1]-a1)-(points[j][1]-a1)*(points[k][0]-a0));
                    if (area<0) area=-area;
                    maxArea=max(maxArea, area);

                }
            }
        }
        return maxArea;
    }
};