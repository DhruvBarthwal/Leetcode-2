class Solution {
public:
    int bestClosingTime(string customers) {
        unordered_map<char,int> closed;
        unordered_map<char, int> open;
        int minTime = INT_MAX;
        int minPenalty = INT_MAX;
        for(char ch : customers) closed[ch]++;
        minTime = 0;
        minPenalty = closed['Y'];
        int time = 1;
        for(char ch : customers){
            open[ch]++;
            closed[ch]--;
            int newPenalty = 0;
            if(open.count('N')) newPenalty += open['N'];
            if(closed.count('Y')) newPenalty += closed['Y'];
            if(newPenalty < minPenalty){
                minPenalty = newPenalty;
                minTime = time;
            }
            time++;
        } 
        return minTime;
    }
};