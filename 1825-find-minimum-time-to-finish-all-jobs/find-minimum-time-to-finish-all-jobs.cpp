
class Solution {
public:
    int n;

    bool func(int idx, vector<int>& jobs, vector<int>& workers, int k, int limit) {
        if (idx == n) return true;
        int curJob = jobs[idx];
        for (int i = 0; i < k; i++) {
            if (workers[i] + curJob <= limit) {
                workers[i] += curJob;
                if (func(idx + 1, jobs, workers, k, limit)) return true;
                workers[i] -= curJob;
            }
            if (workers[i] == 0) break; 
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        sort(jobs.rbegin(), jobs.rend());
        int low = *max_element(jobs.begin(), jobs.end());
        int high = accumulate(jobs.begin(), jobs.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<int> workers(k, 0);
            if (func(0, jobs, workers, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};