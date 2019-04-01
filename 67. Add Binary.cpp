/*
	Given two binary strings, return their sum (also a binary string).

	The input strings are both non-empty and contains only characters 1 or 0.

	Example 1:

	Input: a = "11", b = "1"
	Output: "100"
	Example 2:

	Input: a = "1010", b = "1011"
	Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {

        if(a.size() < b.size())     swap(a,b);
        int len = a.size()+ 1;
        string ans(len,'0');

        int carry = 0;
        int i;
        for(i = 1;i<b.size()+ 1;i++){
            int sum = a[a.size()-i] - '0' + b[b.size() - i] - '0' + carry;
            carry = sum>>1;
            ans[len - i]+= sum%2;            
        }

        for(;i<len;i++){
            if(carry){
                if(a[a.size()-i] == '1'){
                    ans[len - i] = '0';
                }
                else{
                    ans[len - i] = '1';
                    carry = 0;
                }
            }
            else{
                ans[len-i] = a[a.size()-i];
            }
        }
        ans[0] += carry;

        auto pos = ans.find_first_not_of("0");
        if(pos == string::npos){
            return "0";
        }
        else{
            return ans.substr(pos);
        }
    }
};