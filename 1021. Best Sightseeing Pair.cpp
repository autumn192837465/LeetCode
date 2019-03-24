/*
	Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.

	The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, minus the distance between them.

	Return the maximum score of a pair of sightseeing spots.

	 

	Example 1:

	Input: [8,1,5,2,6]
	Output: 11
	Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
	 

	Note:

	2 <= A.length <= 50000
	1 <= A[i] <= 1000
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;

        // the max A[i] + i before j;
        int maxI = A[0];
        int sum = 0;
        for(int j=1;j<A.size();j++){
            sum = A[j] - j + maxI;
            ans = max(ans,sum);
            maxI = max(A[j] + j,maxI);
        }
        return ans;
    }
};