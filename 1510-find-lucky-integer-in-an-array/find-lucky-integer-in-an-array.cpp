class Solution {
public:
    int findLucky(vector<int>& arr) {
        int result=-1;
        
        sort(arr.begin(),arr.end());

        for(int i=1;i<arr.size();i++){
            int count=1;
            while(i<arr.size() && arr[i-1]==arr[i]){
                count++;
                i++;
            }
            if(count==arr[i-1]){
                result=count;
            }
            

        }

        return result;
    }
};