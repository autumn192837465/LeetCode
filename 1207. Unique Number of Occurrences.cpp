/*
	Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

	 

	Example 1:

	Input: arr = [1,2,2,1,1,3]
	Output: true
	Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
	Example 2:

	Input: arr = [1,2]
	Output: false
	Example 3:

	Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
	Output: true
	 

	Constraints:

	1 <= arr.length <= 1000
	-1000 <= arr[i] <= 1000
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        sort(arr.begin(),arr.end());

        map<int,bool> m;
        map<int,bool>::iterator m_iter;

        int occurrence = 1;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == arr[i-1]){
                occurrence++;
            }
            else{
                m_iter = m.find(occurrence);
                if(m_iter == m.end()){
                    m.insert(make_pair(occurrence,true));
                }
                else{
                    return false;
                }
                occurrence = 1;
            }
        }
        m_iter = m.find(occurrence);
        if(m_iter == m.end()){
            return true;
        }
        else{
            return false;
        }

    }
};