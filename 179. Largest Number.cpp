/*
	Given a list of non negative integers, arrange them such that they form the largest number.

	Example 1:

	Input: [10,2]
	Output: "210"
	Example 2:

	Input: [3,30,34,5,9]
	Output: "9534330"
	Note: The result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> strv(nums.size());
        for(int i =0;i<nums.size();i++){
            strv[i] = to_string(nums[i]);
        }
        sort(strv.begin(),strv.end(),Compare);

        string ans;
        for(auto i:strv){
            ans += i;
        }
        
        return (ans[0] == '0')?"0":ans;
    }
    static bool Compare(string a,string b){

        return (a+b).compare(b+a) > 0;
    }
};