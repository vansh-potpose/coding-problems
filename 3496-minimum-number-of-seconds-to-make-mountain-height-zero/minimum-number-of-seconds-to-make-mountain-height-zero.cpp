
//Approach 1
class Solution {
public:
    typedef long long ll;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        //approach 1
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        // next_free_time base_time piles_eaten
        for(auto it:workerTimes){
            pq.push({it,it,1});
        }
        ll ans=0,currHeight=mountainHeight;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll maxTimeHeWorked=it[0];
            ll baseTime=it[1];
            ll reduced=it[2];
            ans=max(ans,maxTimeHeWorked);
            currHeight--;
            if(currHeight==0)break;
            ll nextheight=reduced+1;
            ll totalTimeToBreak=(baseTime*(nextheight)*(nextheight+1))/2;
            pq.push({totalTimeToBreak,baseTime,nextheight});
        }
        return ans;
    }
};