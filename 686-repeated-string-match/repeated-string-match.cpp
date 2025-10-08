class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length(), m = b.length();
        string A = a;
        
        int count = 1;
        while(A.size() < b.size()){
            A += a;
            count++;
        }
        if( A.find(b) != string::npos) return count;

        //1 +a extra as if abpve case is edges with same size;
        A += a;
        count++;
        if( A.find(b) != string::npos) return count;

        return -1;
        //pls upvote
    }
};
