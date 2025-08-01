class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
           for(int j=0;j<=i;j++){
                if(i>0 && j-1>=0 && j!=i){
                    temp.push_back(v[i-1][j-1]+v[i-1][j]);
                }else{
                    temp.push_back(1);
                }
           }
           v.push_back(temp);
        }
        return v;
    }
};