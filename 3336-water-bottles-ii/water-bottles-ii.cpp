class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        //initalization
        int ans = 0;
        int emptyBottles = 0;
        while(numBottles != 0){
            emptyBottles += numBottles;
            ans += numBottles;
            numBottles = 0;

            while(emptyBottles >= numExchange){
                emptyBottles -= numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return ans;
    }
};