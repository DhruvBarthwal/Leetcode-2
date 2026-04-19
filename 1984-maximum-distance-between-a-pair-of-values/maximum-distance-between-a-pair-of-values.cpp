class Solution {
public:
    int m;
    int binarySearch(int val, int i, vector<int>&nums2){
        int s = i;
        int e = m-1;
        int mid = s + (e-s)/2;
        int len = 0;
        while(s<=e){
            if(nums2[mid] >= val){
                len = max(len,mid -i);
                s = mid+1;
            }
            else e = mid -1;
            mid = s + (e-s)/2;
        }
        return len;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        m = nums2.size();
        int count = 0;
        for(int i =0;i<n;i++){
            int val = nums1[i];
            int dist = binarySearch(val,i,nums2);
            count = max(count,dist);
        }
        return count;
    }
};