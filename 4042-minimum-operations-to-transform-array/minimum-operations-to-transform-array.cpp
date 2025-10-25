class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int v = nums2.back();
        int n = nums1.size();
        long long mini = LLONG_MAX;
        long long result = 0;
        for(int i = 0;i<n;i++){
            int a = nums1[i], b = nums2[i];
            result += abs(a-b);
            if((a<= v && v <=b) || (b<= v && v<=a)) mini = 0;
            else {
                mini = min(mini,(long long)min(abs(b-v), abs(a-v)));
            }
        }
        return result + mini + 1;
    }
};