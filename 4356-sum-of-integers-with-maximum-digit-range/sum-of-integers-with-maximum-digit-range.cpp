class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        long long ans = 0;
        unordered_map<int,long long> mp;
        for(auto &num : nums){
            int maxi = 0, mini = INT_MAX;
            int temp = num;
            while(temp > 0){
                int d = temp % 10;
                maxi = max(maxi,d);
                mini = min(mini,d);
                temp /= 10;
            }
            int x = maxi - mini;
            if(mp.count(x)) mp[x] += num;
            else mp[x] = num; 
        }
        for(auto &[num,cnt] : mp){
            cout<< num << " " <<cnt<<" ";
            if(maxRange < num){
                maxRange = num;
                ans = cnt;
            }
        }
        return ans;
    }
};