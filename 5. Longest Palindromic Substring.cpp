/*
	There are two sorted arrays nums1 and nums2 of size m and n respectively.

	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

	You may assume nums1 and nums2 cannot be both empty.

	Example 1:

	nums1 = [1, 3]
	nums2 = [2]

	The median is 2.0
	Example 2:

	nums1 = [1, 2]
	nums2 = [3, 4]

	The median is (2 + 3)/2 = 2.5
*/

double FindKthNum(vector<int> &A,int m,vector<int> &B,int n,int k){
    // m < n
    if(m > n)
        return FindKthNum(B,n,A,m,k);
    if(m == 0)
        return B[k-1];
    else if(n == 0)
        return A[k-1];
    if(k == 1)
        return min(A[0],B[0]);


    //PrintVector("new A",A);
    //PrintVector("new B",B);
    int pa = min(k/2,m);
    int pb = k-pa;

    if(A[pa -1] < B[pb - 1]){
        A.erase(A.begin(),A.begin() + pa);
        return FindKthNum(A,A.size(),B,B.size(),k - pa);
    }
    else if(A[pa -1] > B[pb -1]){
        B.erase(B.begin(),B.begin() + pb);
        return FindKthNum(A,A.size(),B,B.size(),k - pb);
    }
    else{
        return A[pa - 1];
    }
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1 = nums1;
        vector<int> v2 = nums2;
        int m = nums1.size();
        int n = nums2.size();

        if((m+n) & 0x1)
            return FindKthNum(v1,m,v2,n,(m+n)/2 + 1);
        else{
            double a1 = FindKthNum(nums1,m,nums2,n,(m+n)/2);
            double a2 = FindKthNum(v1,m,v2,n,(m+n)/2 +1);
            //cout<<a1 <<"  "<<a2<<endl;
            return (a1+a2)/2;
        }

    }
};

