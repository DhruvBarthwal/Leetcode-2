class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // window sums
        vector<int> sums(n - k + 1);

        int windowSum = 0;

        for(int i = 0; i < n; i++) {

            windowSum += nums[i];

            if(i >= k)
                windowSum -= nums[i - k];

            if(i >= k - 1)
                sums[i - k + 1] = windowSum;
        }

        int m = sums.size();

        // best left index
        vector<int> left(m);

        int best = 0;

        for(int i = 0; i < m; i++) {

            if(sums[i] > sums[best])
                best = i;

            left[i] = best;
        }

        // best right index
        vector<int> right(m);

        best = m - 1;

        for(int i = m - 1; i >= 0; i--) {

            if(sums[i] >= sums[best])
                best = i;

            right[i] = best;
        }

        vector<int> ans(3, -1);

        int maxTotal = 0;

        // middle interval
        for(int mid = k; mid < m - k; mid++) {

            int l = left[mid - k];
            int r = right[mid + k];

            int total =
                sums[l] +
                sums[mid] +
                sums[r];

            if(total > maxTotal) {

                maxTotal = total;

                ans = {l, mid, r};
            }
        }

        return ans;
    }
};