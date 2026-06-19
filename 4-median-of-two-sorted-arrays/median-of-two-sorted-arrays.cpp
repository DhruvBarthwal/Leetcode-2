class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int end = (n + m) / 2;
        int m1 = 0, m2 = 0;
        int i = 0, j = 0;
        for (int a = 0; a <= end; a++) {
            m2 = m1;
            if (i != n && j != m) {
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            }
            else if(i<n){
                m1 = nums1[i];
                i++;
            }
            else{
                m1 = nums2[j];
                j++;
            }
        }
        double ans = 0;
        if((n + m) % 2 == 0){
            ans = (m1 + m2)/2.0;
        }
        else{
            ans = m1;
        }
        return ans;
    }
};