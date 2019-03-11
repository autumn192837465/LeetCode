/*
	Implement strStr().

	Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

	Example 1:

	Input: haystack = "hello", needle = "ll"
	Output: 2
	Example 2:

	Input: haystack = "aaaaa", needle = "bba"
	Output: -1
	Clarification:

	What should we return when needle is an empty string? This is a great question to ask during an interview.

	For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(needle == "")    return 0;
        else if(haystack == "")  return -1;
        //cout<<haystack<<endl<<needle<<endl;
        int nNum = needle.size();
        int hNum = haystack.size();
        
        // faliure function
        int f[nNum];
        f[0] = 0;
        for(int i=1,preNum =0; i<nNum; i++)
        {
            //cout<<f[i-1]<<" ";
            preNum = f[i-1];
            if(needle[i] == needle[preNum])
            {
                f[i] = ++preNum;
            }
            else
            {
                f[i] = 0;
                while(preNum > 0)
                {
                    preNum = f[preNum -1];
                    if(needle[preNum] == needle[i])
                    {
                        f[i] = ++preNum;
                        break;
                    }
                }
            }
        }
        //cout<<f[nNum -1]<<endl;
        int i=0;
        int n=0;
        for(i=0,n = 0; n<nNum && i<hNum;)
        {
            if(haystack[i] != needle[n])
            {
                if(n == 0)  i++;
                else        n = f[n-1];

            }
            else
            {
                i++;
                n++;
            }
        }

        return (n==nNum)?i-nNum:-1;
    }
};