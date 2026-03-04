class Solution {
public:
    static vector<int> check1(vector<int>& vect, int sz){
        vector<int> ans;
        for(int i=0; i<sz; i++){
            if (vect[i]==1) ans.push_back(i);
        }
        return ans;
    }
    static int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans=0;
        vector<bool> col(n, 0);//already check or not
        for(int i=0; i<m; i++){
            auto idx=check1(mat[i], n);
            int j;
            if (idx.size()==1 && col[(j=idx[0])]==0){
                col[j]=1;
                int count_col1=0;
                for(int k=0; k<m; k++)
                    count_col1+=mat[k][j];
                if (count_col1==1){
                //    cout<<"("<<i<<","<<j<<")\n";
                    ans++;
                }     
            }
            else{
                for(int j: idx)
                    col[j]=1;
            }
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();