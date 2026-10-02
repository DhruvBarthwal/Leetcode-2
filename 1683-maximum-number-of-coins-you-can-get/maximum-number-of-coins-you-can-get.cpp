class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int sum = 0;
        int n = piles.size();
        int j = 0;
        int i = n-2;
        while(j<i){
            sum += piles[i];
            i-=2;
            j++;
        }
        return sum;
    }
};