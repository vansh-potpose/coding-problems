class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0])
            return a[1]<b[1];
            return a[0]<b[0];
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i = 0, day = 0, attended = 0, n = events.size();

        int lastDay = 0;
        for (const auto& e : events)
            lastDay = max(lastDay, e[1]);

        for (day = 1; day <= lastDay; ++day) {
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }

            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                minHeap.pop();
                ++attended;
            }
        }

        return attended;
        
    }
};