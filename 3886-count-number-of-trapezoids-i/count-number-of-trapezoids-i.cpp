class Solution {
public:
    static int countTrapezoids(vector<vector<int>>& points) {
        const long long mod=1e9+7, n=points.size();
        unordered_map<int, int> freq;
        freq.reserve(n);
        for(auto& p: points)
            freq[p[1]]++;
        long long sum=0, c2=0;
        for(auto& [y, f]: freq){
            if (f<=1) continue;
            const long long c=f*(f-1LL)/2LL;
            sum+=c;
            c2+=c*c;
        }
        long long ans=sum*sum-c2;
        ans/=2;
        ans%=mod;
        return ans;
    }
};