class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> count(n, 0);

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > busyRooms;

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                count[room]++;
                busyRooms.push({end, room});
            } else {
                auto [t, room] = busyRooms.top();
                busyRooms.pop();
                count[room]++;
                busyRooms.push({t + (end - start), room});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) ans = i;
        }
        return ans;
    }
};