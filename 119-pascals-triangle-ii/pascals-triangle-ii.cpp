class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);

        for (int i = 0; i < rowIndex; i++) {
            vector<int> newRow;
            newRow.push_back(1);
            for (int j = 1; j < row.size(); j++) {
                newRow.push_back(row[j - 1] + row[j]);
            }
            newRow.push_back(1);
            row = newRow;
        }

        return row;        
    }
};