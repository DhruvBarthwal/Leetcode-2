class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(char &count : tasks){
            mp[count - 'A']++;
        }
        for(auto &[it,val] : mp){
            pq.push(val);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> rem;
            int cycle = n+1;
            while(cycle && !pq.empty()){
                int val = pq.top();
                pq.pop();
                if(val - 1 > 0) rem.push_back(val - 1);
                time++;
                cycle--;
            }
            for(int it : rem){
                pq.push(it);
            }
            if(pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};