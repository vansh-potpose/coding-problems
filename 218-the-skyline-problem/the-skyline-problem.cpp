class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for(auto& b:buildings){
            events.emplace_back(b[0],-b[2]);
            events.emplace_back(b[1],b[2]);
        }

        sort(events.begin(),events.end());

        vector<vector<int>> result;

        priority_queue<int> maxHeap;
        unordered_map<int, int> toRemove;   
        maxHeap.push(0); 
        int prevMax = 0; 

        for(auto&  [x, h]: events){
            if(h<0){
                maxHeap.push(-h);
            }else{
                toRemove[h]++;
            }

            while(toRemove[maxHeap.top()]){
                toRemove[maxHeap.top()]--;
                maxHeap.pop();
            }

            int currMax =maxHeap.top();
            if (currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }  
        return  result;
    }
};