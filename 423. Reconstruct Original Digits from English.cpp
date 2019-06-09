/*
	Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

	Note:
	Input contains only lowercase English letters.
	Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
	Input length is less than 50,000.
	Example 1:
	Input: "owoztneoer"

	Output: "012"
	Example 2:
	Input: "fviefuro"

	Output: "45"
*/

class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(26,0);
        vector<int> vnum(10,0);
        string ans;
        for(int i = 0;i<s.size();i++){
            v[s[i] - 'a']++;
        }

        int num;
        int idx;
        // zero
        num = v['z' - 'a'];
        v['z' - 'a'] -= num;
        v['e' - 'a'] -= num;
        v['r' - 'a'] -= num;
        v['o' - 'a'] -= num;
        vnum[0] += num;
        // two
        num = v['w' - 'a'];
        v['t' - 'a'] -= num;
        v['w' - 'a'] -= num;
        v['o' - 'a'] -= num;
        vnum[2] += num;
        // six
        num = v['x' - 'a'];
        v['s' - 'a'] -= num;
        v['i' - 'a'] -= num;
        v['x' - 'a'] -= num;
        vnum[6] += num;
        // seven
        num = v['s' - 'a'];
        v['s' - 'a'] -= num;
        v['e' - 'a'] -= num;
        v['v' - 'a'] -= num;
        v['e' - 'a'] -= num;
        v['n' - 'a'] -= num;
        vnum[7] += num;
        // four
        num = v['u' - 'a'];
        v['f' - 'a'] -= num;
        v['o' - 'a'] -= num;
        v['u' - 'a'] -= num;
        v['r' - 'a'] -= num;
        vnum[4] += num;
        // five
        num = v['f' - 'a'];
        v['f' - 'a'] -= num;
        v['i' - 'a'] -= num;
        v['v' - 'a'] -= num;
        v['e' - 'a'] -= num;
        vnum[5] += num;
        // one
        num = v['o' - 'a'];
        v['o' - 'a'] -= num;
        v['n' - 'a'] -= num;
        v['e' - 'a'] -= num;
        vnum[1] += num;
        // three
        num = v['r' - 'a'];
        v['t' - 'a'] -= num;
        v['h' - 'a'] -= num;
        v['r' - 'a'] -= num;
        v['e' - 'a'] -= num;
        v['e' - 'a'] -= num;
        vnum[3] += num;

        // eight
        num = v['t' - 'a'];
        v['e' - 'a'] -= num;
        v['i' - 'a'] -= num;
        v['g' - 'a'] -= num;
        v['h' - 'a'] -= num;
        v['t' - 'a'] -= num;
        vnum[8] += num;
        // nine
        num = v['i' - 'a'];
        v['n' - 'a'] -= num;
        v['i' - 'a'] -= num;
        v['n' - 'a'] -= num;
        v['e' - 'a'] -= num;
        vnum[9] += num;



        for(int i = 0;i<10;i++){
            for(int j = 0;j<vnum[i];j++){
                ans += to_string(i);
            }
        }
        return ans;
    }

};