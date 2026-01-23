class Solution {
private:
    long long flipped;
    vector<int> left;
    vector<int> right;
    set<pair<long long, int>> pairSum;
    
    long long getVal(int i, const vector<long long>& array) {
        return array[i];
    }
    
    void add(int i, int N, const vector<long long>& array) {
        if (i >= 0 && i < N) {
            int j = right[i];
            if (j < N) {
                pairSum.insert({array[i] + array[j], i});
                if (array[i] > array[j])
                    flipped++;
            }
        }
    }
    
    void remove(int i, int N, const vector<long long>& array) {
        if (i >= 0 && i < N) {
            int j = right[i];
            if (j < N) {
                auto it = pairSum.find({array[i] + array[j], i});
                if (it != pairSum.end()) {
                    if (array[i] > array[j]) flipped--;
                    pairSum.erase(it);
                }
            }
        }
    }
    
public:
    int minimumPairRemoval(vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return 0;
        
        vector<long long> array(nums.begin(), nums.end());
        flipped = 0;
        left.assign(N, 0);
        right.assign(N, 0);
        pairSum.clear();
        
        for (int i = 0; i < N; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        
        for (int i = 0; i < N - 1; ++i) {
            if (array[i] > array[i + 1])
                flipped++;
            
            pairSum.insert({array[i] + array[i + 1], i});
        }
        
        int op = 0;
        while (flipped > 0 && !pairSum.empty()) {
            auto it = pairSum.begin();
            int i = it->second;
            pairSum.erase(it);
            
            int j = right[i];
            int h = left[i];
            int k = right[j];
            
            remove(h, N, array);
            if (array[i] > array[j]) flipped--;
            remove(j, N, array);
            
            array[i] += array[j];
            
            op++;
            right[i] = k;
            if (k < N)
                left[k] = i;
            
            add(h, N, array);
            add(i, N, array);
        }
        
        return op;
    }
};