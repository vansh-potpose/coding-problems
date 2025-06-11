class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(valueDiff < 0)return false;

        unordered_map<long long, long long> bucket;
        long long width = (long long)valueDiff +1;

        for(int i=0;i<nums.size();i++){
            long long num=(long long)nums[i];
            long long bucketId=num/width;
            if (num<0) --bucketId;

            if(bucket.count(bucketId))return true;

            if(bucket.count(bucketId-1) && abs(num- bucket[bucketId-1])<width) return true;

            if(bucket.count(bucketId+1) && abs(num- bucket[bucketId+1])<width) return true;

            bucket[bucketId]=num;

            if (i >= indexDiff) {
                long long oldNum = (long long)nums[i - indexDiff];
                long long oldBucketId = oldNum / width;
                if (oldNum < 0) --oldBucketId;
                bucket.erase(oldBucketId);
            }

        }
        return false;
    }
};