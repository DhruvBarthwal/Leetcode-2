class Solution {
public:
const long long MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long> freqPrev, freqNext;
        long long count = 0;
        int n = nums.size();
        for(int num : nums) freqNext[num]++;
        for(int num : nums){
            freqNext[num]--;
            int checkVal = num*2;
            if(freqNext[checkVal] > 0 && freqPrev[checkVal] > 0){
                count = (count + (freqNext[checkVal] * freqPrev[checkVal]) % MOD) % MOD;
            } 
            freqPrev[num]++;
        }
        return count;
    }
};