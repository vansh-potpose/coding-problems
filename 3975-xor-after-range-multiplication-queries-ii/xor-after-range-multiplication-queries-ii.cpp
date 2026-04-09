constexpr int sq=317, N=1e5;
long long pref[N+sq];
int bucket[sq], nxt[N+sq];// use arrays to implement linked list
static void add2Bucket(int k, int j){
    nxt[j]=bucket[k];
    bucket[k]=j;    
}
long long Inv[N+1];
class Solution {
public:
    static constexpr int mod=1e9+7;

    //Extended Euclidean modInv
    inline static long long modInv(long long a) {
        long long b=mod; 
        long long x0=1, x1=0; 
        while (b>0) {
            auto [q, r] = div(a, b);
            x0=exchange(x1, x0-q*x1);
            a=exchange(b, r);
        }
        return (x0<0) ? x0+mod : x0;
    }
    static void preInv(){
        if (Inv[1]==1) return ;// compute once
        for(int i=1; i<=N; i++) 
            Inv[i]=modInv(i); 
    }
    
    static int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int n=nums.size(), Block=ceil(sqrt(n)), qz=queries.size();
        memset(bucket, -1, sizeof(bucket));
        preInv();

        for (int j=0; j<qz; j++) {
            auto& q=queries[j];
            int l=q[0], r=q[1], k=q[2];
            long long v=q[3];
            if (k>=Block) {// just multiplying
                for (int i=l; i<=r; i+=k) {
                    long long x=nums[i]*v%mod;
                    nums[i]=x;
                }
            }
            else  add2Bucket(k, j);// insert index j to list bucket[k]
        }

        for (int k=1; k<Block; k++) {
            if (bucket[k]==-1) continue;

            fill(pref, pref+n+k, 1);
            
            for (int idx=bucket[k]; idx!=-1; idx=nxt[idx]) {
                auto& q=queries[idx];
                int l=q[0], r=q[1];
                long long v=q[3], inv=Inv[v];

                pref[l]=(pref[l]*v)%mod;
                r+=k-((r-l)%k);
                if (r<n) {
                    pref[r]=(pref[r]*inv)%mod;
                }
            }

            // Apply the prefix product for this k
            for (int i=0; i<n; i++) {
                if (i>=k) pref[i]=(pref[i]*pref[i-k])%mod;
                if (pref[i]!=1) nums[i]=(nums[i]*pref[i])%mod;
            }
        }

        return accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    }
};
const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();