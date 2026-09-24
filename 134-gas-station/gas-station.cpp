class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalCost = 0;
        int totalGas = 0;
        int tank = 0;
        int s =0;

        for(int i =0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                s = i+1;
                tank = 0;
            }
        }
        if(totalGas < totalCost) return -1;
        return s;
    }
};