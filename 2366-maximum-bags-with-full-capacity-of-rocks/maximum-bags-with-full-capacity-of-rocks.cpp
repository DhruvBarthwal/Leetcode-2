class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for(int i =0;i<n;i++){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int cnt = 0;
        int j =0;
        while(j<n && additionalRocks > 0){
            if(capacity[j] == 0) cnt++;
            else if(capacity[j] <= additionalRocks){
                cnt++;
                additionalRocks -= capacity[j];
            }
            else break;
            j++;
        }
        return cnt;
    }
};