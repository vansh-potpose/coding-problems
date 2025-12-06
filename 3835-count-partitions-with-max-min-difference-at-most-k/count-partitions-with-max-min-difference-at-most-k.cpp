constexpr int N=5e4, mod=1e9+7;
int qMax[N], qMin[N];
int frontX, backX, frontN, backN;

class Solution {
public:
    static int countPartitions(vector<int>& nums, int k) {
        const int n=nums.size();

        //reset monotonic queue
        frontX=frontN=0;
        backX=backN=-1;

        long long cnt=0;
        int* sum=(int*)alloca((n+2)*sizeof(int));
        memset(sum, 0, sizeof(sum));
        sum[1]=1;

        for (int l=0, r=0; r<n; r++) {
            int x=nums[r];

            //maintain max queue
            while (backX>=frontX && nums[qMax[backX]]<=x) backX--;
            qMax[++backX]=r;

            //maintain min queue
            while (backN>=frontN && nums[qMin[backN]]>=x) backN--;
            qMin[++backN]=r;

            // shrink window
            while (nums[qMax[frontX]]-nums[qMin[frontN]]>k) {
                frontX+=(qMax[frontX]==l);
                frontN+=(qMin[frontN]==l);
                l++;
            }

            cnt=(mod+sum[r+1]-sum[l])%mod;
            sum[r+2]=(sum[r+1]+cnt)%mod;
        }
        return cnt;
    }
};