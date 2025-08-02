class Solution {
public:
    long long minCost(vector<int>& B1, vector<int>& B2) {
        int n = B1.size();
        unordered_map<int,int> count;
        int mine = INT_MAX;
        for(int i=0;i<n;i++){
            count[B1[i]]++;
            count[B2[i]]--;

        }
        while(n--){
            B1.pop_back();
            B2.pop_back();
        }
        for(auto it: count){
            if((it.second)%2!=0){
                return -1;
            }
            
            if(it.second>0){
                for(int i=0;i<it.second/2;i++){
                    B1.push_back(it.first);
                }

            }
            else{
                for(int i=0;i<-it.second/2;i++){
                    B2.push_back(it.first);
                }
            }
            
            mine=min(mine,it.first);
        }
        sort(B1.begin(),B1.end());
        sort(B2.begin(),B2.end());
        
        int l1=0, l2=0, r1=B1.size()-1,r2=B2.size()-1;
        long long ans = 0;
        while(l1<=r1 && l2<=r2){
            if(min(B1[l1],B2[r2])<2*mine){
                ans+=min(B1[l1],B2[r2]);
                l1++;
                r2--;
            }
            else{
                ans+=2*mine;
                r1--;
                r2--;
            }
            
        }
        return ans;
    }
};