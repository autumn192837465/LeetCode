/*
	Given a collection of numbers that might contain duplicates, return all possible unique permutations.

	Example:

	Input: [1,1,2]
	Output:
	[
	  [1,1,2],
	  [1,2,1],
	  [2,1,1]
	]
*/
void FindPattern(vector<vector<int>> &ans,vector<int> &nums,int *ansTable,bool *usedTable,int idx,int lastIdx){
    if(idx == nums.size()){
        vector<int> v(ansTable,ansTable+idx);
        ans.push_back(v);
        return;
    }

    if(idx && nums[idx] == nums[idx-1]){
        for(int i=lastIdx;i<nums.size();i++){
            if(!usedTable[i]){
                usedTable[i] = true;
                ansTable[i] = nums[idx];
                FindPattern(ans,nums,ansTable,usedTable,idx+1,i);
                usedTable[i] = false;
                ansTable[i] = 0;
            }
        }
    }
    else{
        for(int i=0;i<nums.size();i++){
            if(!usedTable[i]){
                usedTable[i] = true;
                ansTable[i] = nums[idx];
                FindPattern(ans,nums,ansTable,usedTable,idx+1,i);
                usedTable[i] = false;
                ansTable[i] = 0;
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        if(!nums.size()){
            return ans;
        }

        int ansTable[nums.size()];
        bool usedTable[nums.size()];
        memset(ansTable,0,sizeof(ansTable));
        memset(usedTable,0,sizeof(usedTable));
        sort(nums.begin(),nums.end());

        FindPattern(ans,nums,ansTable,usedTable,0,0);
        return ans;
    }
};

class Solution {
public:
    bool isValid(string str) {
        stack<int> s;
        for(int i =0;i<str.size();i++)   {
            int temp = BracketsToInt(str[i]);
            if(s.empty() || temp <= 3){
                s.push(temp);
            }
            else{                                
                else if( == s.top() + 3) s.pop();
                elsereturn false;

                }
            }
        }
        if(s.empty())            
            return true;
        else
            return false;
    }
};