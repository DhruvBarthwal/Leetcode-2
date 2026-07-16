class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //Initialization
        int n = nums.size();
        int mx = 0;

        //creating prefixGcd
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            nums[i] = gcd(mx,nums[i]);
        }

        //sort prefixGcd
        sort(nums.begin(),nums.end());

        //computing sum and gcd of pairs
        long long sum = 0;
        int i = 0, j = n-1;

        while(i < j){
            sum += gcd(nums[i],nums[j]);
            
            i++;
            j--;
        }

        return sum;
    }
};