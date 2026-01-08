class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq(target.begin(),target.end());
        long long sum = accumulate(target.begin(),target.end(),0LL);
        while(true){
            int x = pq.top();
            pq.pop();
            long long rest = sum - x;
            if(x == 1 || rest == 1) return true;
            if(x < rest || rest == 0 || x % rest == 0) return false;
            x %= rest;
            sum = rest + x;
            pq.push(x);
        }
    }
};