class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1;
        nums2 = _nums2;

        for (int num : nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        freq2[nums2[index]]--;         
        nums2[index] += val;
        freq2[nums2[index]]++;         
    }

    int count(int tot) {
        int cnt = 0;
        for (int a : nums1) {
            int complement = tot - a;
            cnt += freq2[complement];
        }
        return cnt;
    }
};
