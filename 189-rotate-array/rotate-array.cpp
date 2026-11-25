class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int jump = k%n;

        if(jump==0)return;

        int count=0;
        for(int s = 0;count<n;s++){
            int c=s;
            int temp = nums[s];

            do{
                int next= (c+jump)%n;
                int temp2=nums[next];
                nums[next]=temp;
                temp=temp2;
                c=next;
                count++;
            }while(s!=c);
        }

        
    }
};