/*
	The set [1,2,3,...,n] contains a total of n! unique permutations.

	By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"
	Given n and k, return the kth permutation sequence.

	Note:

	Given n will be between 1 and 9 inclusive.
	Given k will be between 1 and n! inclusive.
	Example 1:

	Input: n = 3, k = 3
	Output: "213"
	Example 2:

	Input: n = 4, k = 9
	Output: "2314"
*/
class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> v;
        int factorial = 1;
        int factorialIdx = n-1;

        for(int i=1;i<=n;i++){
            v.push_back(i);
            factorial*=i;
        }
        factorial/=n;

        string ans;

        k--;
        while(k){
            ans += to_string(v[k/factorial]);
            v.erase(v.begin()+k/factorial);

            k = k%factorial;
            factorial/=factorialIdx--;

        }
        for(auto i:v)
            ans += to_string(i);
        return ans;
    }
};