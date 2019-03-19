/*
	The count-and-say sequence is the sequence of integers with the first five terms as following:

	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.

	Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

	Note: Each term of the sequence of integers will be represented as a string.	
*/
string ans[30];

bool hasGenerate = false;
int ctoi(char c){
    return c-'0';
}

void GenerateAns(){
    if(hasGenerate) return;

    ans[0] = "1";

    int count;
    int value;
    for(int i=1;i<30;i++){
        // initialize
        ans[i] = "";
        value = ctoi(ans[i-1][0]);
        count = 1;
        for(int j=1;j<ans[i-1].size();j++){
            if(ctoi(ans[i-1][j]) != value){
                ans[i] += to_string(count) + to_string(value);
                count = 1;
                value = ctoi(ans[i-1][j]);
            }
            else{
                count++;
            }
        }
        ans[i] += to_string(count) + to_string(value);
        //cout<< i << " "<<ans[i]<<endl;
    }

    hasGenerate = true;
}

class Solution {
public:
    string countAndSay(int n) {
        GenerateAns();        
        return ans[n-1];
    }
};