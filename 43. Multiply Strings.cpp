/*
	Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

	Example 1:

	Input: num1 = "2", num2 = "3"
	Output: "6"
	Example 2:

	Input: num1 = "123", num2 = "456"
	Output: "56088"
	Note:

	The length of both num1 and num2 is < 110.
	Both num1 and num2 contain only digits 0-9.
	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
	You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size()+num2.size(),'0');

        int sum,carry = 0;
        for(int i=num1.size();i;i--){
            for(int j=num2.size();j;j--){
                sum = (ans[i+j-1] - '0') + (num1[i-1] - '0') * (num2[j-1] - '0') + carry;
                carry = sum/10;
                ans[i+j-1] = sum%10 + '0';
            }
            ans[i-1]+=carry;
            carry = 0;
        }

        size_t pos = ans.find_first_not_of("0");

        return (pos==string::npos)?"0":ans.substr(pos);
    }
};
