class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> count(n);
        vector<long long> timer(n);

        int itr = 0;

        while (itr < meetings.size()) {
            int start = meetings[itr][0];
            int end = meetings[itr][1];
            long long dur = end - start;

            int room = -1;
            long long earliest = LLONG_MAX;
            int earliestRoom = -1;

            for (int i = 0; i < n; i++) {
                if (timer[i] < earliest) {
                    earliest = timer[i];
                    earliestRoom = i;
                }
                if (timer[i] <= start) {
                    room = i;
                    break;
                }
            }

            if (room != -1) {
                timer[room] = end;
                count[room]++;
            } else {
                timer[earliestRoom] += dur;
                count[earliestRoom]++;
            }

            itr++;
        }

        int max = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > max) {
                max = count[i];
                idx = i;
            }
        }

        return idx;
    }
};