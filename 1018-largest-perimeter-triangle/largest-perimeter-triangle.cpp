class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int peri = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0;i<n;i++){
            int left = i+1, right = n-1;
            while(left <right){
                int a = nums[i], b = nums[left], c = nums[right];
                if(a + b > c){
                    peri = max(peri, a+b+c);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return peri;
    }
};