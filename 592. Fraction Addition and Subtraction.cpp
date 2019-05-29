/*
	Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

	Example 1:
	Input:"-1/2+1/2"
	Output: "0/1"
	Example 2:
	Input:"-1/2+1/2+1/3"
	Output: "1/3"
	Example 3:
	Input:"1/3-1/2"
	Output: "-1/6"
	Example 4:
	Input:"5/3+1/3"
	Output: "2/1"
	Note:
	The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
	Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
	The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
	The number of given fractions will be in the range [1,10].
	The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

class Solution {
public:
    int GCD(int a,int b){
        int t = 1;
        while(t){
            t = a%b;
            a = b;
            b = t;
        }
        return a;
    }

    string fractionAddition(string expression) {
        if(expression[0] != '-'){
            expression = '+' + expression;
        }
        int i = 0;
        int sum = 0;
        int LCM = 7*8*9*10;
        while(i < expression.size()){
            int sign = (expression[i]=='-')?-1:1;
            int n;
            if(expression[i+2] == '0'){
                n = 10;
                i+=4;
            }
            else{
                n = expression[i+1] - '0';
                i+=3;
            }
            int d;
            if(expression[i+1] == '0'){
                d = 10;
                i += 2;
            }
            else{
                d = expression[i] - '0';
                i +=1;
            }
            sum += sign*n*LCM/d;
        }
        if(sum == 0)    return "0/1";

        int divisor = GCD(sum,LCM);

        sum /= divisor;
        LCM /= divisor;
        if(LCM < 0){
            LCM*=-1;
            sum*=-1;
        }

        return to_string(sum) + "/" + to_string(LCM);
    }
};