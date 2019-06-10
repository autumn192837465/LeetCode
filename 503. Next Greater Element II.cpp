/*
	class Solution {
	public:
		vector<int> nextGreaterElements(vector<int>& nums) {
			vector<int> ans(nums.size(),-1);
			if(nums.size() == 0)    return ans;
			stack<int> s;
			s.push(0);
			for(int i = 1;i<nums.size();i++){
				while(!s.empty() && nums[i] > nums[s.top()]){
					ans[s.top()] = nums[i];
					s.pop();
				}
				s.push(i);
			}
			for(int i = 0;i<nums.size();i++){
				while(nums[i] > nums[s.top()]){
					ans[s.top()] = nums[i];
					s.pop();
				}
			}

			return ans;
		}
	};
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        if(nums.size() == 0)    return ans;
        stack<int> s;
        s.push(0);
        for(int i = 1;i<nums.size();i++){
            while(!s.empty() && nums[i] > nums[s.top()]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0;i<nums.size();i++){
            while(nums[i] > nums[s.top()]){
                ans[s.top()] = nums[i];
                s.pop();
            }
        }

        return ans;
    }
};