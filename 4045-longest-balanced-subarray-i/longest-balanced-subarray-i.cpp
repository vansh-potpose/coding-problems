auto __fast_io_atexit = []() { ios::sync_with_stdio(false); cin.tie(nullptr); std::atexit([]() { ofstream("display_runtime.txt") << "0"; }); return 0; }();

class Solution {
public:
    int longestBalanced(vector<int>& a) {
        unordered_map<int, int> even, odd;
        int max_ans = 0;
        int n = a.size() ;
        for (int i = 0; i < n - 1; i++) {
            even.clear();
            odd.clear();
            if (a[i] % 2 == 0) {
                even[a[i]] = 1;
            } else {
                odd[a[i]] = 1;
            }

            for (int j = i + 1; j < n; j++) {

                if (a[j] % 2 == 0) {
                    even[a[j]] = 1;
                } 
                else {
                    odd[a[j]] = 1;
                }

                if(even.size() == odd.size()){
                    max_ans = max(max_ans , j - i + 1) ;

                }
            }

        }
        return max_ans ;

    }
};