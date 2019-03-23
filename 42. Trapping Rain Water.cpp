/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


	The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

	Example:

	Input: [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())  return 0;

        int left = 0;
        int idx = 0;
        int barArea = 0;
        int count = 0;
        int ans = 0;
        for(int i=0;i<height.size();i++){
            if(height[i] >= left){
                idx = i;
                ans += left * count - barArea;
                left = height[i];
                barArea = 0;
                count = 0;

            }
            else{
                barArea += height[i];
                count ++;
            }
        }

        left = height[height.size()-1];
        count = 0;
        barArea = 0;
        for(int i = height.size()-1;i>=idx;i--){
            if(height[i] >= left){
                ans+= left * count - barArea;
                left = height[i];
                barArea = 0;
                count = 0;
            }
            else{
                barArea += height[i];
                count++;
            }
        }

        return ans;
    }
};
