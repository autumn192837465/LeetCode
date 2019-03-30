/*
	Given a collection of intervals, merge all overlapping intervals.

	Example 1:

	Input: [[1,3],[2,6],[8,10],[15,18]]
	Output: [[1,6],[8,10],[15,18]]
	Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
	Example 2:

	Input: [[1,4],[4,5]]
	Output: [[1,5]]
	Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
bool operator<(const Interval &a, const Interval &b) {
    return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {


        vector<Interval> ans;
        sort(intervals.begin(),intervals.end());
        int idx = 1;
        while(idx <= intervals.size()){
            int s = intervals[idx-1].start;
            int e = intervals[idx-1].end;

            while(idx < intervals.size() && intervals[idx].start >= s && intervals[idx].start <= e){
                e = max(e,intervals[idx].end);
                idx++;
            }
            idx++;
            ans.push_back(Interval(s,e));


        }
        return ans;
    }
};