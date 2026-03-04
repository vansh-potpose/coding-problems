class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1, left = 0 , right = matrix[0].size()-1;
        vector <int> spiral;
        while (top <= bottom && left <= right){
            for (int i = left ; i <= right ; i ++){
                spiral.push_back(matrix[top][i]);
            }
            top += 1;

            for (int j = top; j <= bottom ; j++){
                spiral.push_back(matrix[j][right]);
            }
            right -= 1;


            if (top <= bottom){
            for (int k = right; k >= left; k--){
                spiral.push_back(matrix[bottom][k]);
            }
            bottom -= 1;

            }
            if (left <= right){
            for (int l = bottom; l >= top; l--){
                spiral.push_back(matrix[l][left]);
            }
            left += 1;
            }
        }
        return spiral;
    }
};