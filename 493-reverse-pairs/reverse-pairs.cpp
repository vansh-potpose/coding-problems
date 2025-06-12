class Solution {
public:
long long merge(vector<int>& nums,int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int ct=0;
    vector<int> temp;
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        ct += (j - (mid + 1));
    }
     i=low;
     j=mid+1;
    while(i<=mid && j<=high)
    {
            if(nums[j]>nums[i])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                
                j++;
            }

    }
    while(i<=mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++)
    {
        nums[low+i]=temp[i];
    }
    return ct;
    

}
long long mergeSort(vector<int>& nums,int low,int high)

{
    int ct=0;
    if(low>=high) return ct;
    int mid=(low+high)/2;
    ct+=mergeSort(nums,low,mid);
    ct+=mergeSort(nums,mid+1,high);
    ct+=merge(nums,low,mid,high);
    return ct;

}
    int reversePairs(vector<int>& nums) {
         int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};


















