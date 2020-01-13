/*
	Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

	Note:

	The length of both num1 and num2 is < 5100.
	Both num1 and num2 contains only digits 0-9.
	Both num1 and num2 does not contain any leading zero.
	You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() > num2.size()){
            num2 = string(num1.size() - num2.size(),'0') + num2;
        }
        else{
            num1 = string(num2.size() - num1.size(),'0') + num1;
        }
        
        bool carry = false;                
        for(int i = num1.size() - 1; i>= 0; i--){
            char sum = num1[i] + num2[i] - '0' + carry;            
            if(sum > '9'){
                carry = true;
                sum -= 10;
            } 
            else{
                carry = false;
            }
            num1[i] = sum;
        }
        if(carry)
            num1 = "1" + num1;
        
        
        return num1;
    }
};