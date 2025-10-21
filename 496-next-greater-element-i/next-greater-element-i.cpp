class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();

       unordered_map<int,int>mp;
       stack<int>st;

       for(int i=m-1;i>=0;i--){
        int curr=nums2[i];
        while(!st.empty() && st.top()<=curr){
            st.pop();
        }
        if(!st.empty()){
            mp[curr]=st.top();
        }
        else{
            mp[curr]=-1;
        }
        st.push(curr);
       }

       vector<int>ans;
       for(int it:nums1){
        ans.push_back(mp[it]);
       }
       
      return ans;
    }
};