/*
	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

	 


	Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

	 


	The largest rectangle is shown in the shaded area, which has area = 10 unit.

	 

	Example:

	Input: [2,1,5,6,2,3]
	Output: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(0);
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int ans = 0;
        int idx;
        for(int i = 1; i < heights.size();i++){            
            while(heights[i] < heights[ idx = s.top()]){
                s.pop();                
                ans = max(ans, heights[idx] * (i - s.top() - 1));
            }
            s.push(i);
            
        }
        heights.pop_back();
        heights.pop_back();
        return ans;
    }
};
