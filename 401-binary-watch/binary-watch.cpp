class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> temp(10,0);
        vector<string> ans;
        for(int i = 9; i>=0; i--){
            if(turnedOn > 0)
            temp[i] = 1;

            turnedOn--;
        }

        do{
            int hour = 0 , minute = 0 , power = 3;
            for(int i = 0; i<=3 ; i++){
                if(temp[i] == 1)
                hour += pow(2,power);

                power--;
            }

            power = 5;
            for(int i = 4; i<=9 ; i++){
                if(temp[i] == 1)
                minute += pow(2,power);

                power--;
            }

            if((hour >=0 && hour <= 11) && (minute >= 0 && minute <= 59)){
                string time = "";
                if(hour >=0 && hour <= 9){
                    time += to_string(hour);
                }else if(hour == 10 || hour == 11){
                    time += to_string(hour);
                }else{
                    time += "0";
                }
                time += ":";

                if(minute >=0 && minute <= 9){
                    time += "0"+to_string(minute);
                }else if(minute >= 10 && minute <= 59){
                    time += to_string(minute);
                }else{
                    time += "00";
                }

                ans.push_back(time);
            }
            
        }while(next_permutation(temp.begin(),temp.end()));
        return ans;
    }
};