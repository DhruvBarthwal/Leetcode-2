class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num > 0){
            int digit = num % 10;
            ans = ans*10 + digit;
            num /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int length = INT_MAX;
        for(int i = 0;i<n;i++){
            int value = reverse(nums[i]);
            int x = nums[i];
            if(mp.count(x)){
                length = min(length,i - mp[x]);
            }
            mp[value] = i;
        }
        return length == INT_MAX ? -1 : length;
    }
};