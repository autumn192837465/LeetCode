/*
	Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

	Example 1:
	Input: [5, 4, 3, 2, 1]
	Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
	Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
	For the left two athletes, you just need to output their relative ranks according to their scores.
	Note:
	N is a positive integer and won't exceed 10,000.
	All the scores of athletes are guaranteed to be unique.
*/

struct Rank{
    int idx;
    int score;

    Rank(int a,int b){
        idx = a;
        score = b;
    }
};

bool RankSort(Rank a,Rank b){
    return a.score > b.score;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size(),"");
        if(nums.size() == 0)    return ans;
        else if(nums.size() ==1){
            ans[0] = "Gold Medal";
            return ans;
        }
        else if(nums.size()==2){
            if(nums[0] > nums[1]){
                ans[0] = "Gold Medal";
                ans[1] = "Silver Medal";
            }
            else{
                ans[0] = "Silver Medal";
                ans[1] = "Gold Medal";
            }
            return ans;
        }
        vector<Rank> v(nums.size(),Rank(0,0));
        int count = 0;
        for(vector<int>::iterator it = nums.begin();it!=nums.end();it++){
            v[count].score = *it;
            v[count].idx = count;
            count++;
        }

        sort(v.begin(),v.end(),RankSort);

        ans[v[0].idx] = "Gold Medal";
        ans[v[1].idx] = "Silver Medal";
        ans[v[2].idx] = "Bronze Medal";
        count = 4;
        for(vector<Rank>::iterator it = v.begin()+3;it != v.end();it++){
            ans[(*it).idx] = to_string(count++);
        }
        return ans;
    }
};