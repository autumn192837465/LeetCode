/*
	A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

	Each LED represents a zero or one, with the least significant bit on the right.


	For example, the above binary watch reads "3:25".

	Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

	Example:

	Input: n = 1
	Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
	Note:
	The order of output does not matter.
	The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
	The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i = 0;i<=num;i++){
            vector<string> hour;
            GetHour(i,0,8,hour);
            vector<string> minute;
            GetMinute(num-i,0,32,minute);

            for(auto a:hour){
                for(auto b:minute){
                    ans.push_back(a + ":" + b);
                }
            }
        }        
        return ans;
    }
    void GetHour(int num,int sum,int hour,vector<string> &hourStr){

        if(num == 0 && hour == 0){
            if(sum < 12)
                hourStr.push_back(to_string(sum));
            return;
        }
        else if(hour == 0){
            return;
        }
        // don't add light
        GetHour(num,sum,hour/2,hourStr);
        // add light
        GetHour(num - 1,sum+hour,hour/2,hourStr);
        
    }
    void GetMinute(int num,int sum,int minute,vector<string> &minStr){

        if(num == 0 && minute == 0){
            if(sum < 60 && sum >=10)
                minStr.push_back(to_string(sum));
            else if(sum<=10)
                minStr.push_back("0" + to_string(sum));
            return;
        }
        else if(minute == 0){
            return;
        }
        
        // don't add light
        GetMinute(num,sum,minute/2,minStr);
        // add light
        GetMinute(num - 1,sum+minute,minute/2,minStr);
    }
};