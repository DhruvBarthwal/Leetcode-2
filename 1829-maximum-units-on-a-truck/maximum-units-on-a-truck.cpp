class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
            if(b[1] == a[1]) return a[0] > b[0];
            return a[1] > b[1];
        });

        int units = 0;

        for(auto &b : boxTypes){
            if(truckSize >= b[0]){
                truckSize -= b[0];
                units += (b[0] * b[1]);
            }
            else{
                units += (truckSize * b[1]);
                break;
            }
        }
        return units;
    }
};