class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //Initialization
        int n = nums.size();
        int mx = 0;
        vector<long long> prefixGcd(n);

        //creating prefixGcd
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            prefixGcd[i] = gcd(mx,nums[i]);
        }

        //sort prefixGcd
        sort(prefixGcd.begin(),prefixGcd.end());

        //computing sum and gcd of pairs
        long long sum = 0;
        int i = 0, j = n-1;

        while(i < j){
            sum += gcd(prefixGcd[i],prefixGcd[j]);
            
            i++;
            j--;
        }

        return sum;
    }
};