class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.rbegin(),happiness.rend());
        queue<long long> q;

        for(int num : happiness) q.push(num);

        long long subcount = 0, happy = 0;
        while(!q.empty() && k>0){
            long long value = q.front();
            q.pop();
            if(value >= subcount) happy += (value - subcount);
            subcount++;
            k--;
        }
        return happy;
    }
};