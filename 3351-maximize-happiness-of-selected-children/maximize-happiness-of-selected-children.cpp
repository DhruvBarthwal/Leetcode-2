class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.rbegin(),happiness.rend());
        long long subcount = 0, happy = 0;
        int i = 0;
        while(i<n && k--){
            long long value = happiness[i];
            if(value >= subcount) happy += value - subcount;
            subcount++;
            i++;
        }
        return happy;
    }
};